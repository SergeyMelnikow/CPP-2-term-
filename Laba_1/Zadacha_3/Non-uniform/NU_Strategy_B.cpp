#include <iostream>
#include <chrono>
#include <random>

int const N = 100000;

int linearfinderB(int(&a)[N],int destination){
    for (int i=0;i!=N;i+=1){
    if (a[i]==destination){
        return i;
        int box = a[i-1];
        a[i-1] = a[i];
        a[i] = box;
    }}
    return 0;
}

int main(){
    int A[N];
    for (int i=1;i!=N-1;i+=1){
        A[i]=i;}

    unsigned seed = 10001;
    int favorite_elements[N/10];
    for(int i=0;i!=(N/10-1);i+=1){
        favorite_elements[i]=A[i*10];
    }
    std::default_random_engine rng ( seed );
    for (int j=100;j<=N;j+=N/(200)){
    //100 experiments for fixed j
    std::uniform_int_distribution <unsigned> dstr ( 0 , (j/10) );
    auto begin = std::chrono::steady_clock::now( );
    for (int i=0;i!=99;i+=1){
    int random_number = favorite_elements[dstr(rng)];
        linearfinderB(A,random_number);
    }

        auto end = std::chrono::steady_clock::now( );

        auto time_span = std::chrono::duration_cast<std::chrono::microseconds>(end - begin );
        std::cout<<j<<","<<(time_span.count()/100)<<"\n";
    }
}