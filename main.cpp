#include <iostream>
#include<stdio.h>
#include<string.h>


using namespace std;

struct Person {
    char firstname[50];
    char surname[50];
};

void exchange(Person *array, int j, int i) {
    struct Person p;
    strcpy(p.firstname, array[j].firstname);
    strcpy(p.surname, array[j].surname);

    strcpy(array[j].firstname, array[i].firstname);
    strcpy(array[j].surname, array[i].surname);

    strcpy(array[i].firstname, p.firstname);
    strcpy(array[i].surname, p.surname);
}

void shuffle(Person *array, size_t n) {
    if (n > 1) {
        size_t i;
        for (int i = n - 1; i > 0; i--) {
            int j = rand() % n;
            exchange(array, j, i);
        }
    }
}

bool valid(Person *santas, Person* santees, int size) {
    for (int i = 0; i < size; i++) {
        if (strcmp(santas[i].surname, santees[i].surname) == 0) {
            return false;
        }
    }
    return true;
}

int nextInvalidIndex(Person *santas, Person *santees, int size, int index) {
    for (int i = index + 1; i < size; i++) {
        if (strcmp(santas[i].surname, santees[i].surname) == 0) {
            return i;
        }
    }
    return -1;
}

void print(Person *santas, Person *santees, int size) {
    for(int i = 0; i < size; i++) {
        printf("%s %s -> %s %s\n", santas[i].firstname, santas[i].surname, santees[i].firstname, santees[i].surname);
    }
}

int main() {
    srand(time(NULL));






    int size = 7;

    struct Person santas[12];
    struct Person santees[12];


    strcpy(santas[0].firstname, "Luke");
    strcpy(santas[0].surname, "Skywalker");
    strcpy(santas[1].firstname, "Leia");
    strcpy(santas[1].surname, "Skywalker");
    strcpy(santas[2].firstname, "Toula");
    strcpy(santas[2].surname, "Portokalos");
    strcpy(santas[3].firstname, "Gus");
    strcpy(santas[3].surname, "Portokalos");
    strcpy(santas[4].firstname, "Bruce");
    strcpy(santas[4].surname, "Wayne");
    strcpy(santas[5].firstname, "Virgil");
    strcpy(santas[5].surname, "Brigman");
    strcpy(santas[6].firstname, "Lindsey");
    strcpy(santas[6].surname, "Brigman");

    for (int i = 0; i < size; i++) {
        strcpy(santees[i].firstname, santas[i].firstname);
        strcpy(santees[i].surname, santas[i].surname);
    }

    int swaps = 0;

    shuffle(santees, size);

    printf("Starting Allocation:\n");
    printf("================================\n");
    print(santas, santees, size);
    printf("================================\n");

    while (valid(santas, santees, size) == 0) {

        int i1 = nextInvalidIndex(santas, santees, size, 0);
        int i2 = nextInvalidIndex(santas, santees, size, i1);

        if (i1 == -1) {
            i1 = rand() % size;
        }
        if (i2 == -1) {
            i2 = rand() % size;
        }

        while (strcmp(santas[i1].surname, santees[i2].surname) == 0 || strcmp(santas[i2].surname, santees[i1].surname) == 0) {
            i1 = i2;
            i2 = nextInvalidIndex(santas, santees, size, i1);
            if (i1 == -1) {
                i1 = rand() % size;
            }
            if (i2 == -1) {
                i2 = rand() % size;
            }
        }

        swaps += 1;
        exchange(santees, i1, i2);

        printf("After swapping %s %s with %s %s:\n", santas[i1].firstname, santas[i1].surname, santas[i2].firstname, santas[i2].surname);
        printf("================================\n");
        print(santas, santees, size);
        printf("================================\n");
    }

    printf("WE DID IT! (IN 1 RANDOMS %d SWAPS) THE SANTAS ARE:\n", swaps);
    printf("================================\n");
    print(santas, santees, size);
    printf("================================\n");

}