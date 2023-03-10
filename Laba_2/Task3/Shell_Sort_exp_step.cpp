#include <iostream>
#include <chrono>

int const N = 100000;
int permutations = 0;


void Shell_sort(int a[N],
                   int begin_idx,
                   int end_idx,int step){
                    int box;
                    int i=begin_idx;
                    while(i<=end_idx){
                        int j = i;
                        if (j>0){
                        while((a[j]<a[j-step]) and (j>0)){
                            int box = a[j-step];
                            a[j-step]=a[j];
                            a[j]=box;
                            j-=step;
                            permutations+=1;
                            if (j==0){
                              break;
                            }
                        }}
                        i+=step;
                    }
                   }

int main(){
    int A[N];
    for (int i=0;i!=N;i+=1){
        A[i]=N-i;
    }

    for (int j=10;j<=N;j+=N/200){
        int step=j/2;
        auto begin = std::chrono::steady_clock::now( );
        while (step>=1){
        Shell_sort(A,0,j-1,step);
        step=step/2;}
        auto end = std::chrono::steady_clock::now( );
        auto time_span = std::chrono::duration_cast<std::chrono::microseconds>(end - begin );
        std::cout<<j<<","<<(time_span.count())<<" "<<permutations<<"\n";
        permutations = 0;
        for (int i=0;i!=N;i+=1){
        A[i]=N-i;
    }
    }
}