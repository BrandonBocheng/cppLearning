#include <iostream>

// various notations, same signatures
const double * f1(const double ar[], int n);
const double * f2(const double [], int);
const double * f3(const double *, int);
int main() {
    using namespace std;
    double av[3] = {1112.3, 345.3, 789.4};

    const double *(*pf1)(const double *, int) = f1;
    auto pf2 = f2; // automatic type deduction can only used for single value initialization
    cout << "Using pointers to functions:\n";
    cout << "Address value\n";
    cout << (*pf1)(av, 3) << ": " << *(pf1)(av, 3) << endl;
    cout << pf2(av, 3) << ": " << *pf2(av, 3) << endl;

    // pa an array of pointers
    const double *(*pa[3])(const double *, int) = {f1, f2, f3};

    // auto doesn't work with list in
    // but it does work for initializting to a single value
    // pb a pointer to first element of pa

    // auto pb = pa;
    const double * (**pb)(const double *, int) = pa;
    cout << "\nUsing an array of pointers to functions:\n";
    cout << " Address Value\n";
    for (int i = 0; i < 3; i++) {
        cout << pa[i](av, 3) << ": " << *pa[i](av ,3) << endl;
    }

    return 0;
}


const double * f1(const double ar[], int) {
    return ar;
}

const double * f2(const double * ar, int) {
    return ar + 1;
}

const double * f3(const double ar[], int) {
    return ar + 2;
}