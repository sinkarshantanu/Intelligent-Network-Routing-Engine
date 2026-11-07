#include "NetworkRouter.h"

int main() {
    NetworkRouter backend_datacenter;

    backend_datacenter.addLink("Mumbai_Core_A", "Bangalore_Edge_B", 14.2, 0.01, 1000);
    backend_datacenter.addLink("Mumbai_Core_A", "Delhi_Cloud_C", 22.5, 0.002, 5000);
    backend_datacenter.addLink("Bangalore_Edge_B", "Chennai_Data_D", 8.1, 0.05, 800);
    backend_datacenter.addLink("Delhi_Cloud_C", "Chennai_Data_D", 5.3, 0.001, 10000);

    backend_datacenter.optimizeRouting("Mumbai_Core_A", "Chennai_Data_D", "LATENCY");
    backend_datacenter.optimizeRouting("Mumbai_Core_A", "Chennai_Data_D", "THROUGHPUT");

    return 0;
}
