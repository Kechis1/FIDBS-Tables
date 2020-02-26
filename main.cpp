#include <cstdio>
#include <chrono>
#include "cHeapTable.h"
#include "cHashTable.h"
#include "cHeapTable_obj.h"
// #include "cHashTableNoRecursion.h"

#define TKey int
#define TData int

using namespace std;
using namespace std::chrono;

float GetThroughput(int opsCount, float period,
                    int unit = 10e6) {
    return ((float) opsCount / unit) / period;
}

/*
void runHashTable(const int rowCount) {
    auto *hashTable = new cHashTable<TKey, TData>(rowCount);
    TKey key;
    TData data;
    auto t1 = high_resolution_clock::now();
    for (int i = 0; i < rowCount; i++) {
        key = data = i;
        if (!hashTable->Add(key, data)) {
            printf("CriticalError: Record %d insertionFailed! \n", i);
        }
        // for testing only
        */
/*for (int j = 0; j <= i; j++) {
            bool ret = hashTable->Find(j, data);
            if (!ret || data != j) {
                printf("CriticalError : Record %d not found ! \n ", i);
                return;
            }
        }*//*

        if (i % 10000 == 0) {
            printf("#Record inserted : %d \r", i);
        }
    }
    auto t2 = high_resolution_clock::now();
    auto time_span = duration_cast < duration < double >> (t2 - t1);
    printf("Records insertion done, HashTable . Time : %.2f s, Throughput : %.2f mil . op / s . \n", time_span.count(),
           GetThroughput(rowCount, time_span.count()));

    t1 = high_resolution_clock::now();
    for (int i = 0; i < rowCount; i++) {
        bool ret = hashTable->Find(i, data);
        if (!ret || data != i) {
            printf("CriticalError : Record %d not found! \n", i);
        }
        if (i % 10000 == 0) {
            printf("#Records retrieved : %d \r", i);
        }
    }
    t2 = high_resolution_clock::now();
    time_span = duration_cast<duration<double>>(t2 - t1);
    printf("Table scan done, HashTable . Time : %.2f s , Throughput : %.2f mil . op / s . \n ", time_span.count(),
           GetThroughput(rowCount, time_span.count()));
    hashTable->PrintStat();
    delete hashTable;
}

*/

void runObjHeapTable(const int RowCount) {

    auto *table = new cHeapTable_obj<TKey, TData>(RowCount);

    TKey key;
    TData data;

    // start insert
    auto t1 = high_resolution_clock::now();

    for (int i = 0; i < RowCount; i++) {
        key = data = i;
        if (!table->Add(key, data)) {
            printf("Critical Error: Record %d insertion failed!\n", i);
        }
        /*if (i % 10000 == 0) {
            printf("#Record inserted: %d   \r", i);
        }*/
    }

    auto t2 = high_resolution_clock::now();
    duration<double> time_span = duration_cast < duration < double >> (t2 - t1);
    printf("Records insertion done. Time: %.2fs, Throughput: %.2f mil. op/s.\n", time_span.count(),
           GetThroughput(RowCount, time_span.count()));

    // start scan
    t1 = high_resolution_clock::now();

    for (int i = 0; i < RowCount; i++) {
        bool ret = table->Get(i, key, data);
        if (!ret || key != i || data != i) {
            printf("Critical Error: Record %d not found!\n", i);
        }
        /*if (i % 10000 == 0) {
            printf("#Records retrieved: %d   \r", i);
        }*/
    }

    t2 = high_resolution_clock::now();
    time_span = duration_cast < duration < double >> (t2 - t1);
    printf("Get done. Time: %.2fs, Throughput: %.2f mil. op/s.\n", time_span.count(),
           GetThroughput(RowCount, time_span.count()));


    // start scan
    const int findRowCount = 7;
    int keys[] = {0, 100000, 1000000, 2500000, 5000000,
                  8000000, 10000001};
    t1 = high_resolution_clock::now();
    for (int index : keys) {
        bool ret = table->Find(index, data);
        if (!ret || index != data) {
            printf("cHeapTable::Find, Key: %d is not found.\n",
                   index);
        }
    }

    t2 = high_resolution_clock::now();
    time_span = duration_cast < duration < double >> (t2 - t1);
    printf("Table scan done. Time: %.2fs, Throughput: %.2f op/s.\n", time_span.count(),
           (float) findRowCount / time_span.count());

    delete table;
}

void runNonObjHeapTable(const int RowCount) {
    auto *table = new cHeapTable<TKey, TData>(RowCount);

    TKey key;
    TData data;

    // start insert
    auto t1 = high_resolution_clock::now();

    for (int i = 0; i < RowCount; i++) {
        key = data = i;
        if (!table->Add(key, data)) {
            printf("Critical Error: Record %d insertion failed!\n", i);
        }
        /*if (i % 10000 == 0) {
            printf("#Record inserted: %d   \r", i);
        }*/
    }

    auto t2 = high_resolution_clock::now();
    duration<double> time_span = duration_cast < duration < double >> (t2 - t1);
    printf("Records insertion done. Time: %.2fs, Throughput: %.2f mil. op/s.\n", time_span.count(),
           GetThroughput(RowCount, time_span.count()));

    // start scan
    t1 = high_resolution_clock::now();

    for (int i = 0; i < RowCount; i++) {
        bool ret = table->Get(i, key, data);
        if (!ret || key != i || data != i) {
            printf("Critical Error: Record %d not found!\n", i);
        }
        /*if (i % 10000 == 0) {
            printf("#Records retrieved: %d   \r", i);
        }*/
    }

    t2 = high_resolution_clock::now();
    time_span = duration_cast < duration < double >> (t2 - t1);
    printf("Get done. Time: %.2fs, Throughput: %.2f mil. op/s.\n", time_span.count(),
           GetThroughput(RowCount, time_span.count()));


    // start scan
    const int findRowCount = 7;
    int keys[] = {0, 100000, 1000000, 2500000, 5000000,
                  8000000, 10000001};
    t1 = high_resolution_clock::now();
    for (int index : keys) {
        bool ret = table->Find(index, data);
        /*if (!ret || index != data) {
            printf("cHeapTable::Find, Key: %d is not found.\n",
                   index);
        }*/
    }

    t2 = high_resolution_clock::now();
    time_span = duration_cast < duration < double >> (t2 - t1);
    printf("Table scan done. Time: %.2fs, Throughput: %.2f op/s.\n", time_span.count(),
           (float) findRowCount / time_span.count());


    delete table;
}

void runHashTableMemory(const int rowCount, cMemory*memory ) {
    auto *hashTable = new cHashTable<TKey, TData>(rowCount / 2, memory);

    TKey key;
    TData data;
    auto t1 = high_resolution_clock::now();
    for (int i = 0; i < rowCount; i++) {
        key = data = i;
        if (!hashTable->Add(key, data)) {
            printf("CriticalError: Record %d insertionFailed! \n", i);
        }
        // for testing only
        /*for (int j = 0; j <= i; j++) {
            bool ret = hashTable->Find(j, data);
            if (!ret || data != j) {
                printf("CriticalError : Record %d not found ! \n ", i);
                return;
            }
        }*/
        /*if (i % 10000 == 0) {
            printf("#Record inserted : %d \r", i);
        }*/
    }
    auto t2 = high_resolution_clock::now();
    auto time_span = duration_cast < duration < double >> (t2 - t1);
    printf("Records insertion done, HashTable . Time : %.2f s, Throughput : %.2f mil . op / s . \n", time_span.count(),
           GetThroughput(rowCount, time_span.count()));

    t1 = high_resolution_clock::now();
    for (int i = 0; i < rowCount; i++) {
        bool ret = hashTable->Find(i, data);
        if (!ret || data != i) {
            printf("CriticalError : Record %d not found! \n", i);
        }
        /*if (i % 10000 == 0) {
            printf("#Records retrieved : %d \r", i);
        }*/
    }
    t2 = high_resolution_clock::now();
    time_span = duration_cast<duration<double>>(t2 - t1);
    printf("Table scan done, HashTable . Time : %.2f s , Throughput : %.2f mil . op / s . \n ", time_span.count(),
           GetThroughput(rowCount, time_span.count()));
    hashTable->PrintStat();
    delete hashTable;
}
/*

void runHashTableMemoryNoRecursion(const int rowCount, cMemory*memory ) {
    auto *hashTable = new cHashTableNoRecursion<TKey, TData>(rowCount / 2, memory);

    TKey key;
    TData data;
    auto t1 = high_resolution_clock::now();
    for (int i = 0; i < rowCount; i++) {
        key = data = i;
        if (!hashTable->Add(key, data)) {
            printf("CriticalError: Record %d insertionFailed! \n", i);
        }
    }
    auto t2 = high_resolution_clock::now();
    auto time_span = duration_cast < duration < double >> (t2 - t1);
    printf("Records insertion done, HashTable . Time : %.2f s, Throughput : %.2f mil . op / s . \n", time_span.count(),
           GetThroughput(rowCount, time_span.count()));

    t1 = high_resolution_clock::now();
    */
/*for (int i = 0; i < rowCount; i++) {
        bool ret = hashTable->Find(i, data);
        if (!ret || data != i) {
            printf("CriticalError : Record %d not found! \n", i);
        }
    }*//*

    t2 = high_resolution_clock::now();
    time_span = duration_cast<duration<double>>(t2 - t1);
    printf("Table scan done, HashTable . Time : %.2f s , Throughput : %.2f mil . op / s . \n ", time_span.count(),
           GetThroughput(rowCount, time_span.count()));
    hashTable->PrintStat();
    delete hashTable;
}
*/

int main() {
    int const RowCount = 10000000;

   /* printf("\n\nRun non-object heap table \n\n");
    runNonObjHeapTable(RowCount);

    printf("\n\nRun object heap table \n\n");
    runObjHeapTable(RowCount);

    printf("\n\nRun non-cMemory hash table \n\n");
    runHashTable(RowCount);*/

    auto * memory = new cMemory(250000000);
    printf("\n\nRun cMemory hash table . \n");
    runHashTableMemory(RowCount, memory);
    memory->PrintStat();
    delete memory;

    /*auto * memory1 = new cMemory(200000000);
    printf("\n\nRun cMemory hash table no recursion. \n");
    runHashTableMemoryNoRecursion(RowCount, memory1);
    memory1->PrintStat();
    delete memory1;*/

    return 0;
}
