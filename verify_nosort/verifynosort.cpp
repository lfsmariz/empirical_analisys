
#include <iostream> 
#include<chrono>
#include<iomanip>
#include<cstdlib>

  
// returns true if there is triplet with sum equal 
// to 'sum' present in A[]. Also, prints the triplet 
bool find3Numbers(int A[], int arr_size, int sum) 
{ 
    int l, r; 
  
    // Fix the first element as A[i] 
    for (int i = 0; i < arr_size - 2; i++) { 
  
        // Fix the second element as A[j] 
        for (int j = i + 1; j < arr_size - 1; j++) { 
  
            // Now look for the third number 
            for (int k = j + 1; k < arr_size; k++) { 
                if (A[i] + A[j] + A[k] == sum) { 
                    return true; 
                } 
            } 
        } 
    } 
  
    // If we reach here, then no triplet was found 
    return false; 
} 
  
/* Driver program to test above function */
int main() 
{   
    int p = 0;
    int tamanho = 5000;
    while(p!=31)
    {
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
        std::cout << tamanho << std::endl;
        std::cout <<"step: " << p+1 << std::endl;
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

        ++p;
        tamanho += 5000;

    }
 

    return 0; 
} 


