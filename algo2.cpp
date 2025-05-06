// Ekaterina Miakotina and Evan Wenzel

#include <iostream>
#include <vector>

// Algorithm for solving the network delay based on passed in information
int networkDelay(std::vector<std::vector<int>> network, int nodes, int signal, int totNet) {
    // Counter to maintain the total delay across the network, started at -1 at default if there is no delay present
    int counter = -1;

    // Loops through all network nodes to determine any present nodes that are designated that receive the signal
    for (int i = 0; i < totNet; i++) {
        if (network[i][0] == signal) {
            // If there is a node present that will receive the signal, then the counter jumps from -1 to 1
            if (counter == -1) {
                counter++;
            };
            counter++;
        };
    };
    // Returns the total delay
    return counter;
}

int main() {
    char confirm2 = 'y';
    while(confirm2 == 'y' || confirm2 == 'Y') {
        int nodes, signalNode, counter = 0;
        bool vecCheck = true;
        char confirm = 'y';
        std::vector<std::vector<int>> network;
        
        // Loop for the user to input the nodes for the network
        while (confirm == 'y' || confirm == 'Y') {
            std::vector<int> temp;
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

            counter++;

            std::cout << "Do you want to add another set of nodes. [y,n]" << std::endl;
            std::cin >> confirm;
        };
        
        std::cout << "Input the number of nodes within the network" << std::endl;
        std::cin >> nodes;
        std::cout << "Input the source node for the signal" << std::endl;
        std::cin >> signalNode;

        // Returns the final inputs from the user in the format designated in the instructions
        std::cout << "You have inputted: ";
        for (int i = 0; i < counter; i++) {
            std::cout << "[" << network[i][0] << ","
                    << network[i][1] << "," << network[i][2] << "] ";
        };
        std::cout << "n = " << nodes << ", k = " << signalNode << std::endl;

        // Returns the total delay by passing the information within the the network
        std::cout << "The minimum time it takes for all " << nodes << " node(s) to receive this signal is: "
                  << networkDelay(network, nodes, signalNode, counter) << std::endl;
        
        std::cout << "Do you want to check another network? [y,n]" << std::endl;
        std::cin >> confirm2;
    };
};