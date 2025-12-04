#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;

struct Customer {
    string nama;
    int berat;
    string service;  
    int arrivalOrder;
    
    Customer(string n, int w, string s, int order) {
        nama = n;
        berat = w;
        service = s;
        arrivalOrder = order;
    }
    
    int getProcessingTime() const {
        if (service == "express") {
            return berat * 5;  
        } else {
            return berat * 10; 
        }
    }
};

struct ComparePriority {
    bool operator()(const Customer& a, const Customer& b) {
        if (a.service == "express" && b.service == "regular") {
            return false;  
        }
        if (a.service == "regular" && b.service == "express") {
            return true;   
        }
        
        return a.arrivalOrder > b.arrivalOrder;
    }
};

int main() {
    int n;
    cin >> n;
    
    priority_queue<Customer, vector<Customer>, ComparePriority> pq;
    
    for (int i = 0; i < n; i++) {
        string nama, service;
        int berat;
        cin >> nama >> berat >> service;
        
        pq.push(Customer(nama, berat, service, i));
    }
    
    vector<string> processingOrder;
    int totalTime = 0;
    
    while (!pq.empty()) {
        Customer current = pq.top();
        pq.pop();
        
        processingOrder.push_back(current.nama);
        totalTime += current.getProcessingTime();
    }
    
    cout << "Urutan: ";
    for (int i = 0; i < processingOrder.size(); i++) {
        cout << processingOrder[i];
        if (i < processingOrder.size() - 1) {
            cout << " ";
        }
    }
    cout << endl;
    
    cout << "Total waktu: " << totalTime << " menit" << endl;
    
    return 0;
}