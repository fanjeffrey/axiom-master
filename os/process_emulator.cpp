#include <iostream>
#include <string>
#include <sstream>

using namespace std;

typedef struct node
{
    string name;
    int prio;
    int cputime;
    int needtime;
    char state;
    struct node * next;
} PCB;

PCB * ready, * run, * finish;

void print_table_header()
{
    cout << endl << "Process" << "\t" << "Used CPU Time" << "\t" << "Needed CPU Time" << "\t" << "Priority" << "\t" << "Status";    
}

void print_process(PCB * p)
{
    if (p != NULL)
    {
	cout << endl << p->name << "\t" << p->cputime << "\t\t" << p->needtime << "\t\t" << p->prio << "\t\t" << p->state;
    }
}

void print_all_processes()
{
    cout << endl << "--begin--";

    print_table_header();

    print_process(run);

    PCB * p = ready;
    while(p != NULL)
    {
        print_process(p);
        p = p->next;
    }
    
    p = finish;
    while(p != NULL)
    {
        print_process(p);
        p = p->next;
    }

    cout << endl << "--end--" << endl;
}

void enqueue_ready(PCB * process)
{
    if (process == NULL)
    {
	return;
    }

    process->state = 'W';

    if (ready == NULL)
    {
	process->next = ready;
	ready = process;
	
	return;
    }

    PCB * cursor, * insertionLocation;
    cursor = ready;
    insertionLocation = cursor;
    
    bool foundInsertionLocation = false;

    while((cursor != NULL) && ! foundInsertionLocation)
    {
        if (cursor->prio >= process->prio)
        {
            insertionLocation = cursor;
            cursor = cursor->next;
        }
        else
        {
            foundInsertionLocation = true;
        }
    }

    if (insertionLocation != cursor)
    {
        insertionLocation->next = process;
        process->next = cursor;
    }
    else // the process to enqueue has top priority
    {
        process->next = cursor;
        ready = process;
    }

    process = NULL;
}

void dequeue_ready()
{
    if (ready != NULL)
    {
        run = ready;
        ready = ready->next;
        run->state = 'R';
    }
}

void enqueue_finish()
{
    run->state = 'F';
    run->next = finish;
    finish = run;
    run = NULL;
}

void init_ready_queue()
{
    ready = NULL;
    run = NULL;
    finish = NULL;

    PCB * process;

    cout << "Initializing 5 processes in the 'ready' queue ..." << endl;
    for (int i = 1; i <= 5; i++)
    {
        process = new PCB;
	ostringstream os;
	os << "P#" << i;	
        process->name = os.str();
        process->cputime = 0;
        process->needtime = 20 * i;
        process->state = 'W';
        process->prio = 100 - process->needtime;

        enqueue_ready(process);
    }
    cout << "Initializing done." << endl;
}

void execute()
{
    print_all_processes();

    int i = 1;
    dequeue_ready();
    while(run != NULL)
    {
	cout << endl << "Time #" << i << " starting ..." << endl;

        run->cputime += 10;
        run->needtime -= 10;
        run->prio -= 10;

	print_all_processes();

        if (run->needtime == 0)
        {
	    enqueue_finish();
            dequeue_ready();
        }
        else if ((ready != NULL) && (run->prio < ready->prio))
        {
            enqueue_ready(run);
            dequeue_ready();
        }

	cout << endl << "Time #" << i++ << " done." << endl;

	if (i == 50) break;
    }

    print_all_processes();
}

int main()
{
    cout << "starting process emulator ..." << endl;
    init_ready_queue();
    execute();

    return 0;
}

