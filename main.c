#include<stdio.h>
#include<stdlib.h>
#define NUM 10^6


void sorting_assending(int *arr[], int size){
    for(int i = 0; i < size-1; i++){
        for(int j = i+1; j < size; j++){
            if(arr[i] > arr[j]){
                int a = arr[i];
                arr[i] = arr[j];
                arr[j] = a;
            }
        }
    }
}

void sorting_dessending(int *arr[], int size){
    for(int i = 0; i < size-1; i++){
        for(int j = i+1; j < size; j++){
            if(arr[i] < arr[j]){
                int a = arr[i];
                arr[i] = arr[j];
                arr[j] = a;
            }
        }
    }
}

int main(int argc, char *argv[]){
    if(argc > 3){
        printf("Too many argumnet");
        return 1;
    }

    char *input_file_name;
    char *is_unique;
    char *is_reverse;
    char *is_num;


    for(int i = 1; i < argc; i++){
        if(argv[i] == "--reverse"){
            is_reverse = "reverse";
        }
        else if(argv[i] == "--unique"){
            is_unique = "unique";
        }
        else if(argv[i] == "--num"){
            is_num= "num";
        }
        else if(i == 1){
            input_file_name = argv[i];
        }
    }

    FILE *input_file = fopen(input_file_name, "r");

    if(input_file == NULL){
        return 1;
    }

    char number;
    int i = 0;
    char arr[NUM];
    while ((number = fgetc(input_file)) != EOF){
        arr[i] = number;
        i++;
    }

    int size = sizeof(arr)/sizeof(int);
    
    

    fclose(input_file);

    return 0;
}