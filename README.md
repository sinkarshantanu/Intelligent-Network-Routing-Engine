# Intelligent Enterprise Network Routing Engine (C++)

A high-performance backend network optimization engine built in pure C++. This system models server nodes as multi-weighted graphical network maps and evaluates data packet pathways dynamically across varying real-world network parameters like latency delays and throughput capacities.

## 🚀 Key Architectural Optimizations
* **Memory-Optimized Topologies:** Implemented Graph structures via custom STL containers (`std::unordered_map` and vectors) to maintain a space complexity profile of $O(V + E)$.
* **Dynamic Cost Functions:** Features an adaptive evaluation parser transforming raw parameters (like bandwidth limits) into graph cost variables.
* **Low-Latency Architecture:** Employs explicit constant-by-reference data sharing rules (`const &`) to fully protect runtime processing scopes against unnecessary duplication layout overloads.

## 📊 Performance Complexity Profiles
* **Time Complexity:** $O((V + E) \log V)$ utilizing binary minimum priority search queue loops.
* **Space Complexity:** Optimized storage mapping at a fixed $O(V + E)$ scale.
