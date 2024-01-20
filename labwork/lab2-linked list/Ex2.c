#include <stdio.h>
#include <stdlib.h>

#define MAX_CARS 10 

// create Car structure with some info and its datatype
typedef struct {
    int capacity;       
    char id;            
    int passengers;     
} Car;

// create Train structure
typedef struct {
    Car cars[MAX_CARS]; 
    int length;         
} Train;

void initialize_train(Train* train) {
    train->length = 0;
}

// add new cars to the train
void add_car(Train* train, char id, int capacity) {
    if (train->length < MAX_CARS) {
        Car new_car;
        new_car.capacity = capacity;
        new_car.id = id;
        new_car.passengers = 0;
        train->cars[train->length] = new_car;
        train->length++;
    } else {
        printf("The length of car is maximum.\n");
    }
}

// remove the empty car from the train
void remove_empty_cars(Train* train) {
    int i;
    for (i = 0; i < train->length; i++) {
        if (train->cars[i].passengers == 0) {
            int j;
            for (j = i; j < train->length - 1; j++) {
                train->cars[j] = train->cars[j + 1];
            }
            train->length--;
            i--; 
        }
    }
}

// display all cars' information 
void display_train(Train* train) {
    printf("Train information:\n");
    printf("Lenght: %d cars\n", train->length);
    printf("\n");
    printf("car\t| capacity\t| passengers\n");
    printf("--------+---------------+--------------\n");
    int i;
    for (i = 0; i < train->length; i++) {
        printf("%c\t|  %d           |  %d\n",
               train->cars[i].id, train->cars[i].capacity, train->cars[i].passengers);
    }
}

int main() {
    Train train;
    initialize_train(&train);

    
    add_car(&train, '1', 11);
    add_car(&train, '2', 22);
    add_car(&train, '3', 55);
    add_car(&train, '4', 10);

 // put the passengers into cars
    train.cars[0].passengers = 11;
    train.cars[2].passengers = 55;
    train.cars[3].passengers = 10;
    
    remove_empty_cars(&train);

  
    display_train(&train);

    return 0;
}