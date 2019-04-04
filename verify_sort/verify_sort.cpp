#include <bits/stdc++.h> 
#include <iostream> 
#include<chrono>
#include<iomanip>
#include<cstdlib>

  
// returns true if there is triplet with sum equal 
// to 'sum' present in A[]. Also, prints the triplet 

bool find3Numbers(int A[], int arr_size, int sum) 
{ 
    int l, r; 
  
    /* Sort the elements */
    std::sort(A, A + arr_size); 
  
    /* Now fix the first element one by one and find the 
       other two elements */
    for (int i = 0; i < arr_size - 2; i++) { 
  
        // To find the other two elements, start two index 
        // variables from two corners of the array and move 
        // them toward each other 
        l = i + 1; // index of the first element in the 
        // remaining elements 
  
        r = arr_size - 1; // index of the last element 
        while (l < r) { 
            if (A[i] + A[l] + A[r] == sum) { 
                return true; 
            } 
            else if (A[i] + A[l] + A[r] < sum) 
                l++; 
            else // A[i] + A[l] + A[r] > sum 
                r--; 
        } 
    } 
  
    // If we reach here, then no triplet was found 
    return false; 
} 
/* Driver program to test above function */
int main() 
{ 
    int tamanho = 5000;
    int A[tamanho];

    for(size_t i = 0; i < tamanho; i++)
    {
        A[i] = rand()%tamanho+1;
    }

    int sum = rand()%(3*tamanho);
  
    int arr_size = sizeof(A) / sizeof(A[0]); 
    auto start = std::chrono::high_resolution_clock::now(); //Start timer
    bool boleano = find3Numbers(A, arr_size, sum); 
    auto stop = std::chrono::high_resolution_clock::now(); //Stop timer
    std::chrono::duration<double, std::milli> duration_micro = stop - start;
    double duration_sec = duration_micro.count() / 1000;
    std::cout << std::setw(10) << duration_sec << " s | "; 
    std::cout << std::setw(10) << duration_micro.count() << " ms |" << std::endl;
    
    if (boleano == true)
    {
        std::cout << "foi"<< std::endl;
    }
    if (boleano == false)
    {
        std::cout << "nfoi"<< std::endl;
    }
    
    

    return 0; 
} 