#include <iostream>
#include <iomanip>
#include <string>

#define N 6
#define M 4

using namespace std;

struct page 
{
    int lnumber;
    int flag;
    int pnumber;
    int write;
    int dnumber;
} pages[N];

int p[M];
int head;
void initial(void);
int do_mmap(int);
void do_page_fault(int);
void run_first_instruction(int);
void run_a_instruction(int);
void print_page_and_fifoqueue(void);

main()
{
    int laddress, paddress;
    int lnumber, ad, pnumber;
    
    initial();
    print_page_and_fifoqueue();
    run_first_instruction(0x0000);

    cout << "Enter the address of next instruction(0 ~ 32767):" << endl;
    cin >> laddress;
    while (laddress > 32767)
    {
        cout << "Error! The address must be within 0 ~ 32767" << endl;
        cin >> laddress;
    }

    while (laddress != -1)
    {
        lnumber = laddress >> 10;
        if (pages[lnumber].flag == 1)
        {
            paddress = do_mmap(laddress);
            cout << paddress << " <-- physical address" << endl;
            run_a_instruction(paddress);
            cout << "Will this instruction modify the page #" << lnumber << "? (y/n)";
            char change;
            cin >> change;
            if (tolower(change) == 'y')
            {
                pages[lnumber].write = 1;
                print_page_and_fifoqueue();
            }
        }
        else // page fault
        {
            cout << lnumber << " <-- this page is not in the memory." << endl;
            do_page_fault(lnumber);
            continue;
        }

        cout << "Enter the address of next instruction(0 ~ 32767):" << endl;
        cin >> laddress;
	while (laddress > 32767)
        {
            cout << "Error! The address must be within 0 ~ 32767" << endl;
            cin >> laddress;
        }
    }

    cout << "Proccess end!" << endl;
//    system("PAUSE");
    return 0;
}

void initial(void)
{
    int i;
    for(i = 0; i <= 5; i++)
    {
        pages[i].lnumber = i;
        if (i <= M -1)
        {
            cout << "Enter the block number for the page #" << i << ":" << endl;
            cin >> pages[i].pnumber;
            pages[i].flag = 1;
        }
    }

    head = 0;
    for(i = 0; i <= M - 1; i++)
    {
        p[i] = i;
    }
}

void print_page_and_fifoqueue(void)
{
    int i;
    cout << "Page table :---------------------" << endl;
    cout << setw(10) << "lnumber" << setw(9) 
        << "flag" << setw(10) << "pnumber" << setw(10) <<  "write" << setw(10) << "dnumber" << endl;

    for(i = 0; i <= N - 1; i++)
    {
        cout << setw(7) << pages[i].lnumber << setw(10) 
            << pages[i].flag << setw(10) << pages[i].pnumber << setw(10) << pages[i].write << setw(10) << pages[i].dnumber << endl;
    }

    cout << "FIFO queue :---------------------" << endl;
    cout << setw(10) << "NO" << setw(30) << "Page (lnumber)" << endl;
    cout << "head = " << head << endl;
    for(i = 0; i <= M - 1; i++)
    {
        cout << setw(10) << i << setw(15) << p[i] << endl;
    }
}

int do_mmap(int laddress)
{
    int lnumber, ad, pnumber, paddress;
    lnumber = laddress >> 10;
    ad = laddress & 0x3ff;
    pnumber = pages[lnumber].pnumber;
    paddress = pnumber << 10 | ad;

    return paddress;
}

void run_a_instruction(int paddress)
{
    cout << paddress << " <-- the instruction at this address executed." << endl;
}

void run_first_instruction(int laddress)
{
    int lnumber, ad, pnumber, paddress;
    lnumber = laddress >> 10;
    if (pages[lnumber].flag == 1)
    {
        paddress == do_mmap(laddress);
    }

    cout << paddress << " <-- physical address" << endl;
    run_a_instruction(paddress);
    cout << "Will this instruction modify the page #" << lnumber << "? (y/n):";
    char change;
    cin >> change;
    if (tolower(change) == 'y')
    {
        pages[lnumber].write = 1;
        print_page_and_fifoqueue();
    }

    cout << endl << "====The first instruction executed.====" << endl;
}

void write_to_harddisk(int j)
{
    cout << j << " <-- Write the modified page back to disk." << endl;
}

void do_page_fault(int lnumber)
{
    int j;
    j = p[head];
    p[head] = lnumber;
    head = (head + 1) % M;

    if (pages[j].write == 1)
    {
        write_to_harddisk(j);
    }

    pages[j].flag = 0;
    pages[lnumber].flag = 1;
    pages[lnumber].write = 0;
    pages[lnumber].pnumber = pages[j].pnumber;

    cout << lnumber << " <-- this page has been loaded in memory." << endl;
    cout << "Press any key to view the new page table and FIFO queue ..." << endl;
    //system("PAUSE");
    print_page_and_fifoqueue();
}
