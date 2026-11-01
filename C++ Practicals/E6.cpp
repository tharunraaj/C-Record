#include <iostream>
#include <memory>
#include <string>
using namespace std;

class Resource
{
private:
    string name;
    int id;

public:
    Resource(string n, int i)
    {
        name = n;
        id = i;
        cout << "Resource acquired: " << name << " (ID " << id << ")" << endl;
    }
    ~Resource()
    {
        cout << "Resource released: " << name << endl;
    }
    void use()
    {
        cout << "Resource " << name << " is being used" << endl;
    }
};

class MySmartPointer
{
private:
    Resource* ptr;

public:
    MySmartPointer(Resource* p)
    {
        ptr = p;
    }
    ~MySmartPointer()
    {
        delete ptr;
        cout << "Manual smart pointer destroyed" << endl;
    }
    Resource* operator->()
    {
        return ptr;
    }
    MySmartPointer(const MySmartPointer&) = delete;
    MySmartPointer& operator=(const MySmartPointer&) = delete;
};

void runTest(int testNo, string name1, int id1, string name2, int id2,
             string name3, int id3)
{
    cout << "===== Test Case " << testNo << " =====" << endl;

    cout << "----- Manual RAII Smart Pointer -----" << endl;
    {
        MySmartPointer smartPtr(new Resource(name1, id1));
        smartPtr->use();
    }

    cout << "\n----- unique_ptr -----" << endl;
    {
        unique_ptr<Resource> uniquePtr = make_unique<Resource>(name2, id2);
        uniquePtr->use();
    }

    cout << "\n----- shared_ptr -----" << endl;
    {
        shared_ptr<Resource> sharedPtr1 = make_shared<Resource>(name3, id3);
        shared_ptr<Resource> sharedPtr2 = sharedPtr1;
        sharedPtr1->use();
        cout << "Shared Pointer Count: " << sharedPtr1.use_count() << endl;
    }
    cout << endl;
}

int main()
{
    runTest(1, "Printer", 101, "Scanner", 202, "Projector", 303);
    runTest(2, "Router", 7, "Monitor", 45, "Laptop", 88);

    cout << "Program completed successfully." << endl;
    return 0;
}