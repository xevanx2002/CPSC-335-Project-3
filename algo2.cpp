// Ekaterina Miakotina and Evan Wenzel

#include <iostream>
#include <vector>
int networkDelay(std::vector<std::vector<int>> network, int nodes, int signal) {
    int counter = -1;
    for (int i = 0; i < network.size(); i++) {
        if (network[i][1] == signal) {
            if (counter == -1) {
                counter = 1;
            };
            counter++;
        };
    };
    return counter;
}

int main() {
    bool choice = true;
    while(choice == true) {
        int nodes, signalNode;
        bool vecCheck = true;
        std::vector<std::vector<int>> network;
        
        while (vecCheck) {
            std::vector<int> temp;
            char confirm;
            int temp1 = 0,
                temp2 = 0,
                temp3 = 0;

            std::cout << "Input the source node" << std::endl;
            std::cin >> temp1;
            temp.push_back(temp1);
            std::cout << "Input the target node" << std::endl;
            std::cin >> temp2;
            temp.push_back(temp2);
            std::cout << "Input the time to travel from source to target" << std::endl;
            std::cin >> temp3;
            temp.push_back(temp3);

            std::cout << "The vector has been made" << std::endl;
            std::cout << temp[0] << " " << temp[1] << " " << temp[2] << std::endl;
            network.push_back(temp);

            std::cout << "Do you want to add another set of nodes. [y,n]" << std::endl;
            std::cin >> confirm;

            if(confirm != 'y' || confirm != 'Y') {
                vecCheck = false;
            };
        };
        
        std::cout << "Input the number of nodes within the network" << std::endl;
        std::cin >> nodes;
        std::cout << "Input the source node for the signal" << std::endl;
        std::cin >> signalNode;

        std::cout << "You have inputted: [";
        for (int i = 0; i < nodes; i++) {
            std::cout << "[" << network[i][0] << ","
                    << network[i][1] << "," << network[i][2] << "],";
        };
        std::cout << " n = " << nodes << ", k = " << signalNode << std::endl;
        std::cout << network.size() << std::endl;

        std::cout << "The minimum time it takes for all " << nodes << " to receive this signal is "
                  << networkDelay(network, nodes, signalNode) << std::endl;
    };
};