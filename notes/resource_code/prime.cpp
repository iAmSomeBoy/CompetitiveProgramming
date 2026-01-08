#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

// Function to check if a number is prime
bool isPrime(int num) {
    if (num <= 1) return false;
    if (num == 2) return true;
    if (num % 2 == 0) return false;
    
    int limit = sqrt(num);
    for (int i = 3; i <= limit; i += 2) {
        if (num % i == 0) return false;
    }
    return true;
}

// Function to generate primes in a range and save to file
void generateAndSavePrimes(int start, int end, const string& filename) {
    ofstream outFile(filename);
    
    if (!outFile.is_open()) {
        cerr << "Error: Could not create file " << filename << endl;
        return;
    }
    
    cout << "Generating prime numbers between " << start << " and " << end << "..." << endl;
    
    int count = 0;
    for (int i = start; i <= end; i++) {
        if (isPrime(i)) {
            outFile << i << " ";
            count++;
            
            // Optional: Add line break after every 10 primes for readability
            if (count % 10 == 0) {
                outFile << "\n";
            }
        }
    }
    
    outFile.close();
    cout << "Successfully saved " << count << " prime numbers to " << filename << endl;
}

// Function to read primes from file into a vector
vector<int> readPrimesFromFile(const string& filename) {
    vector<int> primes;
    ifstream inFile(filename);
    
    if (!inFile.is_open()) {
        cerr << "Error: Could not open file " << filename << endl;
        return primes;
    }
    
    int prime;
    while (inFile >> prime) {
        primes.push_back(prime);
    }
    
    inFile.close();
    cout << "Read " << primes.size() << " prime numbers from " << filename << endl;
    return primes;
}

// Function to display primes with formatting
void displayPrimes(const vector<int>& primes) {
    if (primes.empty()) {
        cout << "No primes to display." << endl;
        return;
    }
    
    cout << "\nPrime Numbers (" << primes.size() << " total):" << endl;
    cout << "==================================" << endl;
    
    for (size_t i = 0; i < primes.size(); i++) {
        cout << primes[i] << "\t";
        if ((i + 1) % 8 == 0) {  // Display 8 numbers per line
            cout << endl;
        }
    }
    cout << endl << endl;
}

// Function 1: Find prime factors of a number using the stored primes
void findPrimeFactors(const vector<int>& primes, int number) {
    cout << "Prime factors of " << number << ": ";
    
    if (number <= 1) {
        cout << "None (number must be greater than 1)" << endl;
        return;
    }
    
    int n = number;
    vector<int> factors;
    
    for (int prime : primes) {
        if (prime * prime > n) break;
        
        while (n % prime == 0) {
            factors.push_back(prime);
            n /= prime;
        }
    }
    
    if (n > 1) {
        // If n is still greater than 1, it might be a prime not in our list
        factors.push_back(n);
    }
    
    // Display factors
    if (factors.empty()) {
        cout << number << " is prime" << endl;
    } else {
        for (size_t i = 0; i < factors.size(); i++) {
            cout << factors[i];
            if (i < factors.size() - 1) cout << " × ";
        }
        cout << endl;
    }
}

// Function 2: Check if a number is prime using the stored prime list
void checkPrimeUsingList(const vector<int>& primes, int number) {
    // First, check if it's in our prime list
    if (binary_search(primes.begin(), primes.end(), number)) {
        cout << number << " is prime (found in the list)" << endl;
    } else {
        // Check if it's divisible by any prime in our list
        bool isPrimeNumber = true;
        
        if (number <= 1) {
            isPrimeNumber = false;
        } else {
            for (int prime : primes) {
                if (prime * prime > number) break;
                if (number % prime == 0) {
                    isPrimeNumber = false;
                    break;
                }
            }
        }
        
        if (isPrimeNumber) {
            cout << number << " is prime (not in list, but verified)" << endl;
        } else {
            cout << number << " is not prime" << endl;
        }
    }
}

// Function 3: Sum of primes in a range
void sumPrimesInRange(const vector<int>& primes, int start, int end) {
    long long sum = 0;
    int count = 0;
    
    for (int prime : primes) {
        if (prime >= start && prime <= end) {
            sum += prime;
            count++;
        }
        if (prime > end) break;
    }
    
    cout << "Sum of primes between " << start << " and " << end << ": " << sum << endl;
    cout << "Number of primes in this range: " << count << endl;
}

// Function 4: Find primes within a specific range
void findPrimesInRange(const vector<int>& primes, int start, int end) {
    cout << "Primes between " << start << " and " << end << ":" << endl;
    
    bool foundAny = false;
    for (int prime : primes) {
        if (prime >= start && prime <= end) {
            cout << prime << " ";
            foundAny = true;
        }
        if (prime > end) break;
    }
    
    if (!foundAny) {
        cout << "None found in the loaded prime list.";
    }
    cout << endl;
}

// Function 5: Count prime pairs with a specific difference (e.g., twin primes: difference = 2)
void countPrimePairs(const vector<int>& primes, int difference) {
    int count = 0;
    
    for (size_t i = 1; i < primes.size(); i++) {
        if (primes[i] - primes[i - 1] == difference) {
            count++;
            if (count <= 5) {  // Show first 5 pairs
                cout << "Pair " << count << ": " << primes[i - 1] << " and " << primes[i] << endl;
            }
        }
    }
    
    cout << "Total prime pairs with difference " << difference << ": " << count << endl;
}

int main() {
    vector<int> primes;
    string filename = "prime_numbers.txt";
    int choice;
    
    cout << "=============================================" << endl;
    cout << "     PRIME NUMBER FILE OPERATIONS PROGRAM    " << endl;
    cout << "=============================================" << endl;
    
    do {
        cout << "\nMENU:" << endl;
        cout << "1. Generate prime numbers and save to file" << endl;
        cout << "2. Load prime numbers from file" << endl;
        cout << "3. Display loaded prime numbers" << endl;
        cout << "4. Find prime factors of a number" << endl;
        cout << "5. Check if a number is prime" << endl;
        cout << "6. Sum of primes in a range" << endl;
        cout << "7. Find primes within a specific range" << endl;
        cout << "8. Count prime pairs with specific difference" << endl;
        cout << "9. Exit" << endl;
        cout << "Enter your choice (1-9): ";
        cin >> choice;
        
        switch(choice) {
            case 1: {
                int start, end;
                cout << "Enter the range (start and end): ";
                cin >> start >> end;
                
                if (start < 2) {
                    cout << "Start must be at least 2. Adjusting to 2." << endl;
                    start = 2;
                }
                
                if (start > end) {
                    cout << "Invalid range. Start cannot be greater than end." << endl;
                } else {
                    generateAndSavePrimes(start, end, filename);
                }
                break;
            }
            
            case 2: {
                primes = readPrimesFromFile(filename);
                break;
            }
            
            case 3: {
                displayPrimes(primes);
                break;
            }
            
            case 4: {
                if (primes.empty()) {
                    cout << "Please load primes first (option 2)." << endl;
                } else {
                    int number;
                    cout << "Enter a number to find its prime factors: ";
                    cin >> number;
                    findPrimeFactors(primes, number);
                }
                break;
            }
            
            case 5: {
                if (primes.empty()) {
                    cout << "Please load primes first (option 2)." << endl;
                } else {
                    int number;
                    cout << "Enter a number to check if it's prime: ";
                    cin >> number;
                    checkPrimeUsingList(primes, number);
                }
                break;
            }
            
            case 6: {
                if (primes.empty()) {
                    cout << "Please load primes first (option 2)." << endl;
                } else {
                    int start, end;
                    cout << "Enter the range (start and end): ";
                    cin >> start >> end;
                    sumPrimesInRange(primes, start, end);
                }
                break;
            }
            
            case 7: {
                if (primes.empty()) {
                    cout << "Please load primes first (option 2)." << endl;
                } else {
                    int start, end;
                    cout << "Enter the range (start and end): ";
                    cin >> start >> end;
                    findPrimesInRange(primes, start, end);
                }
                break;
            }
            
            case 8: {
                if (primes.empty()) {
                    cout << "Please load primes first (option 2)." << endl;
                } else {
                    int difference;
                    cout << "Enter the difference to find prime pairs (e.g., 2 for twin primes): ";
                    cin >> difference;
                    countPrimePairs(primes, difference);
                }
                break;
            }
            
            case 9: {
                cout << "Exiting program. Goodbye!" << endl;
                break;
            }
            
            default: {
                cout << "Invalid choice. Please enter a number between 1 and 9." << endl;
                break;
            }
        }
        
    } while (choice != 9);
    
    return 0;
}