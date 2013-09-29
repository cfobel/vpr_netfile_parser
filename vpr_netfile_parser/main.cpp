#include <iostream>
#include <string>
#include "VprNetParser.hpp"

using namespace std;


int main(int argc, char const* argv[]) {
    string net_file = "/var/benchmarks/mcnc/tseng.net";
    VprNetFileParser<unsigned int> r(net_file);
    r.init();
    r.parse();
    cout << "block_label_to_net_labels_.size(): "
         << r.block_label_to_net_labels_.size() << endl;
    cout << "block_labels.size(): "
         << r.block_labels_.size() << endl;
    return 0;
}
