#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <chrono>
using namespace std;
using namespace std::chrono;
typedef struct {
    int x;
    int y;
} point;

void swapPoint(point* a, point* b) {
    point temp = *a;
    *a = *b;
    *b = temp;
}

int partitionX(vector<point>& set, int low, int high) {
    int pivot = set[high].x;
    int i = low;
    for (int j = low; j < high; ++j) {
        if (set[j].x < pivot) {
            swapPoint(&set[i], &set[j]);
            i++;
        }
    }
    swapPoint(&set[i], &set[high]);
    return i;
}

void quickSortX(vector<point>& set, int low, int high) {
    if (low < high) {
        int pi = partitionX(set, low, high);
        quickSortX(set, low, pi - 1);
        quickSortX(set, pi + 1, high);
    }
}

int partitionY(vector<point>& set, int low, int high) {
    int pivot = set[high].y;
    int i = low;
    for (int j = low; j < high; ++j) {
        if (set[j].y < pivot) {
            swapPoint(&set[i], &set[j]);
            i++;
        }
    }
    swapPoint(&set[i], &set[high]);
    return i;
}

void quickSortY(vector<point>& set, int low, int high) {
    if (low < high) {
        int pi = partitionY(set, low, high);
        quickSortY(set, low, pi - 1);
        quickSortY(set, pi + 1, high);
    }
}

void collinearParallelToX(vector<point>& set) {
    quickSortY(set, 0, set.size() - 1);
    int i = 0;
    cout << "Collinear points parallel to X-axis:\n\n";
    while (i < set.size()) {
        vector<point> temp_collinear_set;
        temp_collinear_set.push_back(set[i]);
        int j = i + 1; // Initialize j inside the loop
        while (j < set.size() && set[j].y == set[i].y) {
            temp_collinear_set.push_back(set[j]);
            ++j; // Increment j here
        }
        if (temp_collinear_set.size() >= 3) {
            for (int k = 0; k < temp_collinear_set.size(); ++k) {
                cout << "(" << temp_collinear_set[k].x << "," << temp_collinear_set[k].y << ") ";
            }
            cout << endl;
        }
        i = j; // Update i after processing all collinear points
    }
}

void collinearParallelToY(vector<point>& set) {
    quickSortX(set, 0, set.size() - 1);
    int i = 0;
    cout << "Collinear points parallel to Y-axis:\n\n";
    while (i < set.size()) {
        vector<point> temp_collinear_set;
        temp_collinear_set.push_back(set[i]);
        int j = i + 1; // Initialize j inside the loop
        while (j < set.size() && set[j].x == set[i].x) {
            temp_collinear_set.push_back(set[j]);
            ++j; // Increment j here
        }
        if (temp_collinear_set.size() >= 3) {
            for (int k = 0; k < temp_collinear_set.size(); ++k) {
                cout << "(" << temp_collinear_set[k].x << "," << temp_collinear_set[k].y << ") ";
            }
            cout << endl;
        }
        i = j; // Update i after processing all collinear points
    }
}

int main() {
    vector<point> point_set(3000);
    for (int i = 0; i < 3000; ++i) {
        point_set[i].x = rand() % 1000;  // x coordinate value from 0 to 999
        point_set[i].y = rand() % 1000;  // y coordinate value from 0 to 999
    }
    auto start1 = high_resolution_clock::now();
    collinearParallelToX(point_set);
    auto stop1 = high_resolution_clock::now();
    auto duration1= duration_cast<microseconds>(stop1 - start1);

    cout << "\n\n";



    auto start2 = high_resolution_clock::now();
    collinearParallelToY(point_set);
    auto stop2 = high_resolution_clock::now();
    auto duration2 = duration_cast<microseconds>(stop2 - start2);

    cout<<"Time taken to find find collinear point parallel to X axis: "<<duration1.count()<<" microseconds\n\n";
    cout<<"Time taken to find find collinear point parallel to Y axis: "<<duration2.count()<<" microseconds\n\n";


    return 0;
}
