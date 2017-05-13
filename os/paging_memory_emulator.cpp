#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

struct page
{
	int page_no;
	int memory_block_no;
	int disk_block_no;
	bool in_memory;
	bool changed;
};

struct instruction
{
	string name;
	int address;
};

const int PAGE_TABLE_SIZE = 7;
const int FIFO_QUEUE_SIZE = 4;
const int INSTRUCTION_QUEUE_SIZE = 9;

page page_table[PAGE_TABLE_SIZE];
int fifo_queue[FIFO_QUEUE_SIZE];
instruction instructions[INSTRUCTION_QUEUE_SIZE];
int head;

void init_page_table(void);
void init_fifo_queue(void);
void init_instructions(void);
void run_instructions(void);
int parse_page_no(int);
int translate_logic_address(int);
void load_page(int);
void print_page_table(void);
void print_fifo_queue(void);

int main()
{
	init_page_table();
	init_fifo_queue();
	init_instructions();

	print_page_table();
	print_fifo_queue();

	run_instructions();

	cout << endl << "Press Enter to exit." << endl;
	cin.ignore();
	cin.get();

	return 0;
}

void run_instructions()
{
	cout << endl << "Starting to execute instructions ..." << endl;

	for (int i = 0; i < INSTRUCTION_QUEUE_SIZE; i++)
	{
		cout << endl << "INSTRUCTION #" << i << " " << instructions[i].name << " " << instructions[i].address << endl;

		int page_no = parse_page_no(instructions[i].address);
		if (!page_table[page_no].in_memory)// page fault, not in memory
		{
			load_page(page_no);
		}

		cout << "Translating logical address: " << instructions[i].address << " ..." << endl;
		int physic_address = translate_logic_address(instructions[i].address);
		cout << "Got physical address: " << physic_address << endl;
		cout << ">> executing instruction: " << instructions[i].name << " @ " << physic_address << endl;
		if (instructions[i].name == "save")
		{
			page_table[page_no].changed = true;
		}

		print_page_table();
		print_fifo_queue();
	}
}

void init_page_table(void)
{
	for (int i = 0; i < PAGE_TABLE_SIZE; i++)
	{
		page_table[i].page_no = i;
		page_table[i].changed = false;
		page_table[i].disk_block_no = 100 + i;
		if (i <= PAGE_TABLE_SIZE / 2)
		{
			page_table[i].in_memory = 1;
			cout << "Enter the memory block number for the page #" << i << ":" << endl;
			cin >> page_table[i].memory_block_no;
		}
	}
}

void init_fifo_queue(void)
{
	for (int i = 0; i < FIFO_QUEUE_SIZE; i++)
	{
		fifo_queue[i] = i;
	}

	head = 0;
}

void init_instructions(void)
{
	instructions[0].name = "add";
	instructions[0].address = 0x111;

	instructions[1].name = "add";
	instructions[1].address = 0x444;

	instructions[2].name = "save";
	instructions[2].address = 0x888;

	instructions[3].name = "load";
	instructions[3].address = 0xddd;

	instructions[4].name = "add";
	instructions[4].address = 0x1111;

	instructions[5].name = "save";
	instructions[5].address = 0x1414;

	instructions[6].name = "load";
	instructions[6].address = 0x1818;

	instructions[7].name = "add";
	instructions[7].address = 0x999;

	instructions[8].name = "save";
	instructions[8].address = 0x777;
}

void print_page_table(void)
{
	cout << "--------page table--------" << endl;
	cout << setw(7) << "page_no"
		<< setw(16) << "memory_block_no"
		<< setw(15) << "disk_block_no"
		<< setw(11) << "in_memory"
		<< setw(9) << "changed" << endl;

	for (int i = 0; i < PAGE_TABLE_SIZE; i++)
	{
		cout << setw(7) << page_table[i].page_no
			<< setw(16) << page_table[i].memory_block_no
			<< setw(15) << page_table[i].disk_block_no
			<< setw(11) << page_table[i].in_memory
			<< setw(9) << page_table[i].changed << endl;
	}
}

void print_fifo_queue(void)
{
	cout << "--------FIFO queue--------" << endl;
	cout << setw(7) << "#" << setw(10) << "page_no" << endl;

	for (int i = 0; i < FIFO_QUEUE_SIZE; i++)
	{
		cout << setw(7) << i << setw(10) << fifo_queue[i] << endl;
	}

	cout << "FIFO head = " << head << endl;
}

int parse_page_no(int logical_address)
{
	cout << "Parsing page no from logical address: " << logical_address << " ..." << endl;
	int page_no = logical_address >> 10;
	cout << "Got page no: " << page_no << endl;

	return page_no;
}

int translate_logic_address(int logic_address)
{
	int page_no = logic_address >> 10;
	int offset = logic_address & 0x3ff;
	int memory_block_no = page_table[page_no].memory_block_no;
	int physic_address = memory_block_no << 10 | offset;

	return physic_address;
}

void save_to_disk(int page_no)
{
	cout << "#" << page_no << " <-- this page got changed, save it back to disk." << endl;
}

void load_page(int in_page_no)
{
	cout << "#" << in_page_no << " <-- this page is not in the memory. start swapping ..." << endl;

	cout << "Checking FIFO queue ..." << endl;
	int out_page_no = fifo_queue[head];
	cout << "#" << out_page_no << " <-- this page is found at FIFO head, will be swapped out ..." << endl;
	fifo_queue[head] = in_page_no;
	head = (head + 1) % FIFO_QUEUE_SIZE;

	// the page swapped out
	if (page_table[out_page_no].changed)
	{
		save_to_disk(out_page_no);
		page_table[out_page_no].changed = false;
	}
	page_table[out_page_no].in_memory = false;
	cout << "#" << out_page_no << " <-- this page has been swapped out." << endl;

	// the page swapped in
	page_table[in_page_no].memory_block_no = page_table[out_page_no].memory_block_no;
	page_table[in_page_no].changed = false;
	page_table[in_page_no].in_memory = true;
	cout << "#" << in_page_no << " <-- this page has been swapped in." << endl;

	print_page_table();
	print_fifo_queue();
}

