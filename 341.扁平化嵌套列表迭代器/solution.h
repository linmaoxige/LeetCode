class NestedIterator {
private:
  stack<NestedInteger> st;
public:
  NestedIterator(vector<NestedInteger> &nestedList) {
    for (auto iter = nestedList.rbegin(); iter != nestedList.rend(); iter++) {
      st.push(*iter);
    }
  }

  int next() {
    auto t = st.top();
    st.pop();
    return t.getInteger();
  }

  bool hasNext() {
    while (!st.empty()) {
      auto cur = st.top();
      if (cur.isInteger()) return true;
      st.pop();
      auto curList = cur.getList();
      for (auto iter = curList.rbegin(); iter != curList.rend(); iter++) {
        st.push(*iter);
      }
    }
    return false;
  }
};