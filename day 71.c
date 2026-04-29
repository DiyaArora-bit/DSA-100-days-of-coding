#include <stdio.h>
#include <string.h>

#define EMPTY -1

int main() {
    int m, q;
    
   
    scanf("%d", &m);
    
    int hashTable[m];
    

    for(int i = 0; i < m; i++) {
        hashTable[i] = EMPTY;
    }
    
    // Number of queries
    scanf("%d", &q);
    
    while(q--) {
        char operation[10];
        int key;
        
        scanf("%s %d", operation, &key);
        
        
        if(strcmp(operation, "INSERT") == 0) {
            int h = key % m;
            int i = 0;
            
            while(i < m) {
                int index = (h + i * i) % m;
                
                if(hashTable[index] == EMPTY) {
                    hashTable[index] = key;
                    break;
                }
                
                i++;
            }
        }
        
        
        else if(strcmp(operation, "SEARCH") == 0) {
            int h = key % m;
            int i = 0;
            int found = 0;
            
            while(i < m) {
                int index = (h + i * i) % m;
                
                if(hashTable[index] == key) {
                    found = 1;
                    break;
                }
                
                if(hashTable[index] == EMPTY) {
                    break;
                }
                
                i++;
            }
            
            if(found)
                printf("FOUND\n");
            else
                printf("NOT FOUND\n");
        }
    }
    
    return 0;
}