#include <iostream>
#include <cstring>
#include <chrono>
#include <utility>
using namespace std;
using namespace chrono;

class String
{
private:
    char* data;
    size_t length;

public:
    String(const char* str = "")
    {
        length = strlen(str);
        data = new char[length + 1];
        strcpy(data, str);
    }
    String(const String& other)
    {
        length = other.length;
        data = new char[length + 1];
        strcpy(data, other.data);
    }
    String(String&& other) noexcept
    {
        data = other.data;
        length = other.length;
        other.data = nullptr;
        other.length = 0;
    }
    String& operator=(const String& other)
    {
        if (this != &other)
        {
            delete[] data;
            length = other.length;
            data = new char[length + 1];
            strcpy(data, other.data);
        }
        return *this;
    }
    String& operator=(String&& other) noexcept
    {
        if (this != &other)
        {
            delete[] data;
            data = other.data;
            length = other.length;
            other.data = nullptr;
            other.length = 0;
        }
        return *this;
    }
    ~String()
    {
        delete[] data;
    }
    void display() const
    {
        if (data != nullptr)
            cout << data << endl;
    }
};

template <typename T>
String createString(T&& value)
{
    return String(forward<T>(value));
}

void runTest(int testNo, const char* text, int size, const char* forwardText)
{
    cout << "===== Test Case " << testNo << " =====" << endl;

    String original(text);

    auto startCopy = high_resolution_clock::now();
    for (int i = 0; i < size; i++)
    {
        String copy = original;
    }
    auto endCopy = high_resolution_clock::now();
    auto copyTime = duration_cast<milliseconds>(endCopy - startCopy);

    auto startMove = high_resolution_clock::now();
    for (int i = 0; i < size; i++)
    {
        String temp(text);
        String moved = move(temp);
    }
    auto endMove = high_resolution_clock::now();
    auto moveTime = duration_cast<milliseconds>(endMove - startMove);

    String forwarded = createString(forwardText);
    cout << "Perfect Forwarding Result: ";
    forwarded.display();

    cout << "Copy Operation Time: " << copyTime.count() << " milliseconds" << endl;
    cout << "Move Operation Time: " << moveTime.count() << " milliseconds" << endl;
    cout << endl;
}

int main()
{
    runTest(1, "Data structures and algorithms in C++", 50000, "Forwarding test one");
    runTest(2, "Smart pointers and move semantics", 20000, "Forwarding test two");

    cout << "Program completed successfully." << endl;
    return 0;
}