class NumberContainers {
private:
    unordered_map<int, int> container;
    unordered_map<int, set<int>> number_to_ind;
public:
    NumberContainers() {
        
    }
    
    void change(int index, int number) {
        if(container.find(index) != container.end()){
            int prev_num = container[index];
            number_to_ind[prev_num].erase(index);
            if(number_to_ind[prev_num].empty()){
                number_to_ind.erase(prev_num);
            }
        }
        container[index] = number;
        number_to_ind[number].insert(index);
    }
    
    int find(int number) {
        if(number_to_ind.find(number) != number_to_ind.end()){
            return *number_to_ind[number].begin();
        }
        return -1;
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */