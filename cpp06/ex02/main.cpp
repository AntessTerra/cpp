#include "TypeDetector.hpp"

int main(void){
	int N = 1;
	Base** unknown = generate(N);

	for (int i = 0; i < N; i++){
		identify(unknown[i]);
		identify(*unknown[i]);
		delete unknown[i];
	}

	delete[] unknown;
}
