class listnode
{
public:
    int value;
    int min;
    listnode* next;
public:
    listnode(int val, int min) :value(val), min(min) {

    }

};
class MinStack {
private:
    listnode* head;

public:
    /** initialize your data structure here. */
    MinStack() {
    }

    void push(int x) {
        if (head == NULL)
        {
            head = new listnode(x, x);
            head->next = NULL;

        }
        else
        {
            int tempv = x < (head->min) ? x : (head->min);
            listnode* temp = new listnode(x, tempv);
            temp->next = head;
            head = temp;

        }
    }

    void pop() {
        if (head != NULL)
        {
            listnode* temp = head->next;
            listnode* temp2 = head;
            delete temp2;
            temp2 = NULL;
            head = temp;
        }

    }

    int top() {
        return head->value;
    }

    int getMin() {
        return head->min;
    }
};