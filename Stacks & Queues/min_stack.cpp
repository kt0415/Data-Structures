#include <bits/stdc++.h>
using namespace std;

//Approach 1: TC:O(1), SC:O(2N)
// class MinStack {
//   stack < pair < int, int >> st;

//   public:
//     void push(int x) {
//       int min;
//       if (st.empty()) {
//         min = x;
//       } else {
//         min = std::min(st.top().second, x);
//       }
//       st.push({x,min});
//     }

//   void pop() {
//     st.pop();
//   }

//   int top() {
//     return st.top().first;
//   }

//   int getMin() {
//     return st.top().second;
//   }
// };

//Approach 2: TC:O(1), SC:O(N)
class MinStack {
  stack < long long > st;
  long long mini;
  public:
    /** initialize your data structure here. */
    MinStack() {
      while (st.empty() == false) st.pop();
      mini = INT_MAX;
    }

  void push(int value) {
    long long val = long long(value);
    if (st.empty()) {
      mini = val;
      st.push(val);
    } else {
      if (val < mini) {
        st.push(2 *val*1LL - mini);
        mini = val;
      } else {
        st.push(val);
      }
    }
  }

  void pop() {
    if (st.empty()) return;
    long long el = st.top();
    st.pop();

    if (el < mini) {
      mini = 2 * mini - el;
    }
  }

  int top() {
    if (st.empty()) return -1;

    long long el = st.top();
    if (el < mini) return mini;
    return el;
  }

  int getMin() {
    return mini;
  }
};


