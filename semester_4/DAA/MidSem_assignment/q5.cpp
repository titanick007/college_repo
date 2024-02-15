#include <iostream>
#include <chrono>
#include <string>
#include <cmath>

using namespace std;
using namespace std::chrono;

bool is_pythagorean_triplet(int a, int b, int c) {
    return a * a + b * b == c * c;
}

bool is_nearly_pythagorean_triplet(int a, int b, int c) {
    // Tolerance for nearly Pythagorean triplet
    double tolerance = 1e-6;
    return abs(a * a + b * b - c * c) < tolerance;
}

bool is_valid_triplet(int a, int b, int c) {
    return a > 0 && b > 0 && c > 0 && a + b > c && a + c > b && b + c > a;
}


void check_partitions(int num) {
    string num_str = to_string(num);
    for (int i = 1; i < num_str.length(); i++) {
        for (int j = i + 1; j < num_str.length(); j++) {
            int a = stoi(num_str.substr(0, i));
            int b = stoi(num_str.substr(i, j - i));
            int c = stoi(num_str.substr(j));

            if (is_valid_triplet(a, b, c)) {
                cout << "Partition: (" << a << ", " << b << ", " << c << ")" << endl;
                if (is_pythagorean_triplet(a, b, c)) {
                    cout << "It forms a Pythagorean triplet." << endl;
                } else if (is_nearly_pythagorean_triplet(a, b, c)) {
                    cout << "It is nearly a Pythagorean triplet." << endl;
                } else {
                    cout << "It is not a Pythagorean triplet." << endl;
                }

                if (a * a + b * b == c * c || a * a + c * c == b * b || b * b + c * c == a * a) {
                    cout << "It's a right-angled triangle." << endl;
                } else {
                    cout << "It's not a right-angled triangle." << endl;
                }
                cout << endl;
            }
        }
    }
}

int main() {
    int num;
    cout << "Enter a 5-digit number: ";
    cin >> num;

    auto start = high_resolution_clock::now();

    check_partitions(num);

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "Time taken by algorithm: " << duration.count() << " microseconds\n\n";

    return 0;
}
