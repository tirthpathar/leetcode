class MyStack {
public:
    queue<int> q;

    MyStack() {

    }

    void push(int x) {
        q.push(x);

        int n = q.size();

        // Move the previous elements behind the new element
        for (int i = 1; i < n; i++) {
            q.push(q.front());
            q.pop();
        }
    }

    int pop() {
        int x = q.front();
        q.pop();
        return x;
    }

    int top() {
        return q.front();
    }

    bool empty() {
        return q.empty();
    }
};