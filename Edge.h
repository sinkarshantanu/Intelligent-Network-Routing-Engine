#ifndef EDGE_H
#define EDGE_H

#include <string>

// Enterprise data structure representing a multi-weighted network channel
struct Edge {
    std::string destination;
    double latency;       // Network delay metric (ms)
    double packet_loss;   // Link reliability factor (0.0 to 1.0)
    int bandwidth;        // Network throughput capacity (Mbps)
};

#endif // EDGE_H
