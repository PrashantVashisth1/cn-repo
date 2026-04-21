#include <iostream>
using namespace std;

// Objective function
int f(int x) {
    return -x * x + 10 * x + 5;
}

// Hill Climbing Algorithm
void hillClimbing(int start, int stepSize, int maxIterations) {
    int current = start;
    int currentValue = f(current);

    cout << "Start at x = " << current 
         << " f(x) = " << currentValue << endl;

    for (int i = 0; i < maxIterations; i++) {
        int left = current - stepSize;
        int right = current + stepSize;

        int leftValue = f(left);
        int rightValue = f(right);

        // Choose best neighbor
        if (leftValue > currentValue) {
            current = left;
            currentValue = leftValue;
        }
        else if (rightValue > currentValue) {
            current = right;
            currentValue = rightValue;
        }
        else {
            // No better neighbor → stop
            break;
        }

        cout << "Move to x = " << current 
             << " f(x) = " << currentValue << endl;
    }

    cout << "\nFinal Solution: x = " << current 
         << " f(x) = " << currentValue << endl;
}

int main() {
    int start, stepSize, maxIterations;

    cout << "Enter starting value: ";
    cin >> start;

    cout << "Enter step size: ";
    cin >> stepSize;

    cout << "Enter max iterations: ";
    cin >> maxIterations;

    hillClimbing(start, stepSize, maxIterations);

    return 0;
}