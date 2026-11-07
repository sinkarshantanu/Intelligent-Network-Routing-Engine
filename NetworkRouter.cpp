#include "NetworkRouter.h"
#include <iostream>
#include <queue>
#include <limits>
#include <iomanip>

const double INF = std::numeric_limits<double>::max();

void NetworkRouter::addNode(const std::string& node_id) {
    if (adjacency_list.find(node_id) == adjacency_list.end()) {
        adjacency_list[node_id] = std::vector<Edge>();
    }
}

void NetworkRouter::addLink(const std::string& source, const std::string& dest, double latency, double packet_loss, int bandwidth) {
    addNode(source);
    addNode(dest);
    adjacency_list[source].push_back({dest, latency, packet_loss, bandwidth});
    adjacency_list[dest].push_back({source, latency, packet_loss, bandwidth});
}

double NetworkRouter::calculateCost(const Edge& edge, const std::string& metric_priority) {
    if (metric_priority == "LATENCY") return edge.latency;
    if (metric_priority == "THROUGHPUT") return 1000.0 / static_cast<double>(edge.bandwidth);
    return edge.latency + (edge.packet_loss * 50.0);
}

void NetworkRouter::optimizeRouting(const std::string& source, const std::string& destination, const std::string& optimization_metric) {
    std::unordered_map<std::string, double> min_cost;
    std::unordered_map<std::string, std::string> parent_node;
    
    for (const auto& pair : adjacency_list) {
        min_cost[pair.first] = INF;
    }

    auto comp = [](const std::pair<double, std::string>& a, const std::pair<double, std::string>& b) {
        return a.first > b.first;
    };
    std::priority_queue<std::pair<double, std::string>, std::vector<std::pair<double, std::string>>, decltype(comp)> pq(comp);

    min_cost[source] = 0.0;
    pq.push({0.0, source});

    while (!pq.empty()) {
        std::string current = pq.top().second;
        double current_cost = pq.top().first;
        pq.pop();

        if (current == destination) break;
        if (current_cost > min_cost[current]) continue;

        for (const auto& edge : adjacency_list[current]) {
            double travel_cost = calculateCost(edge, optimization_metric);
            if (min_cost[current] + travel_cost < min_cost[edge.destination]) {
                min_cost[edge.destination] = min_cost[current] + travel_cost;
                parent_node[edge.destination] = current;
                pq.push({min_cost[edge.destination], edge.destination});
            }
        }
    }

    printRouteResults(source, destination, min_cost, parent_node, optimization_metric);
}

void NetworkRouter::printRouteResults(const std::string& src, const std::string& dest, 
                                       std::unordered_map<std::string, double>& min_cost, 
                                       std::unordered_map<std::string, std::string>& parent, 
                                       const std::string& metric) {
    if (min_cost[dest] == INF) {
        std::cout << "\nPath not found from " << src << " to " << dest << "\n";
        return;
    }

    std::vector<std::string> path;
    std::string current = dest;
    while (current != src) {
        path.push_back(current);
        current = parent[current];
    }
    path.push_back(src);

    std::cout << "\n=============================================";
    std::cout << "\n📡 ENTERPRISE ROUTING LOGS (" << metric << ")";
    std::cout << "\n=============================================\n";
    std::cout << "🚀 Optimal Node Sequence: ";
    for (int i = path.size() - 1; i >= 0; --i) {
        std::cout << path[i] << (i > 0 ? " -> " : "");
    }
    std::cout << "\n📊 Optimization Score: " << std::fixed << std::setprecision(2) << min_cost[dest] << "\n";
}
