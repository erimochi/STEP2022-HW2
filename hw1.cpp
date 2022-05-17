#include <iostream>
#include <iomanip> // setprecision
#include <time.h>
#include <vector>
#include <algorithm> //max()


using namespace std;
long long n_limit = 1e4;

vector < int > prepare_ns(const int nlen,const int nmin);
vector < double > measure_times(const vector < int > ns , const int nlen);
double t_calc_product(const int n);


int main(int argc, char *argv[]){
	// prepare
	int nmin=1;
	int nmax=10;
	if(argc==1){}
	else if(argc==2){ 
		nmax= stoi(argv[1]);
		if(nmax <1 || nmax > n_limit){cout << "N should be: 1 < nlen <= " << n_limit <<endl; return 0;}
	}else if(argc==3){ 
		nmin= stoi(argv[1]);
		nmax= stoi(argv[2]);
		if(nmax <1 || nmax > n_limit){cout << "N should be: 1 < N <= " << n_limit <<endl; return 0;}
		if(nmin <1 || nmin > n_limit){cout << "N should be: 1 < N0 <= " << n_limit <<endl; return 0;}
	}else{cout << "Usage: ./hw1 [N0(minimum matrix size)] N(maximum matrix size) " << endl; return 0;}
	
	int nlen = nmax-nmin+1;
	if(nlen <= 0 ){cout << "N should be: 1 < N0 <= N <= " << n_limit <<endl; return 0;}
	
	// calculate
	vector < int > ns = prepare_ns(nlen,nmin);	
	vector < double > times = measure_times(ns, nlen);
	
	// output result

	cout << nlen << endl;
	for(int i=0; i<nlen;i++){
		cout << ns[i] << " " << fixed << setprecision(10) <<  times[i] << endl;
	}
	return 0;
}


vector < int > prepare_ns(const int nlen,const int nmin){
	vector < int > ns;
	for(int i=nmin; i<nlen+nmin; i++){
		ns.push_back(i);
	}
	return ns;
}


vector < double > measure_times(const vector < int > ns , const int nlen){
 	// average time for each N
	vector < double > ts_mean; // calc times for all N 
	int m = 10; //repeat m times and take average
	double t_sum; //sum of time (→average)
	int n;
	for(int i=0; i<nlen; i++){
		t_sum = 0;
		n = ns[i];
		for(int j=0; j<m; j++){t_sum += t_calc_product(n);}
		ts_mean.push_back(t_sum/m);
	}
	return ts_mean;
}


double t_calc_product(const int n){
	// measure time to calculate  matrix product (A[N,N] * B[N,N])
	int A[n][n];
	int B[n][n];
	int C[n][n];
	clock_t  start = clock();
	for(int i=0;i<n;i++){
		for(int j=0; j<n; j++){
			for(int k=0; k<n; k++){
				C[i][j] += A[i][k] * B[k][j]; 	
			}
		}
	}
	clock_t stop = clock();

	return  (double)(stop-start)/CLOCKS_PER_SEC ;
}


/*
参考
多次元配列の初期化：
https://www.ibm.com/docs/ja/xl-c-aix/12.1.0?topic=initializers-initialization-arraysv
https://zenn.dev/yohhoy/articles/quiz-init-vector

*/