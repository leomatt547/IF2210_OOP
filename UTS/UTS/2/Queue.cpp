#include <iostream>

using namespace std;

template <class T>
class Queue {
  protected:
    T *elements;
    int nElements;
    int pertama;
  public:
    Queue(){
        this->nElements = 0;
        this->pertama - 0;
    }
    ~Queue(){
        //
    }
    virtual void enqueue(const T& input){
        if ((nElements - pertama) < 10){
            elements[nElements] = input;
            this->nElements++;
        }else{
            throw QueuePenuh();
        }
    }
    T dequeue(){
        if((nElements - pertama) == 0){
            T output = elements[pertama];
            this->pertama++;
            return output;
        }else{
            throw QueueKosong;
        }
    }
    void print(){
        for (int i=pertama; i<nElements; i++){
            cout << elements[i] << endl;
        }
    }
};

template <class T>
class PriorityQueue : public Queue<T> {
  private:
    int *priorities;
  public:
    PriorityQueue(): public Queue(){
        priorities = new int[100];
    }
    ~PriorityQueue(){
        //
    }
    void enqueue(const T& input, int prio){
        Queue<T>::enqueue(input);
        priorities[Queue<T>::nElements] = prio;
    }
};

class QueuePenuh: public exception{
    public:
        const char * what() const throw(){
            return "Queue Penuh";
        }
};

class QueueKosong : public exception{
    public:
        const char * what() const throw(){
            return "Queue Kosong";
        }
};

int main() {
  try
    {
        Queue<int> Q;
        PriorityQueue<int> R;
        Q = Queue<int>();
        Q.enqueue(5);
        Q.enqueue(4);
        R.enqueue(7,3);
    }
    catch(exception& e){
        cout << e.what() << endl;
    }
}
