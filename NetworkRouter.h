#ifndef NETWORK_ROUTER_H
#define NETWORK_ROUTER_H

#include <vector>
#include <unordered_map>
#include <string>
#include "Edge.h"

class NetworkRouter {
private:
    std::unordered_map<std::string, std::vector<Edge>> adjacency_list;
    double calculateCost(const Edge& edge, const std::string& metric_priority);
    void printRouteResults(const std::string& src, const std::string& dest, 
                           std::unordered_map<std::string, double>& min_cost, 
                           std::unordered_map<std::string, std::string>& parent, 
                           const std::string& metric);

public:
    void addNode(const std::string& node_id);
    void addLink(const std::string& source, const std::string& dest, double latency, double packet_loss, int bandwidth);
    void optimizeRouting(const std::string& source, const std::string& destination, const std::string& optimization_metric);
};

#endif // NETWORK_ROUTER_H
