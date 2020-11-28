#include <CGAL/Simple_cartesian.h>
#include <CGAL/Orthogonal_incremental_neighbor_search.h>
#include <CGAL/Search_traits_2.h>
#include <CGAL/Kernel_d/Vector_d.h>

#include "VectorCaracteristico.h"
#include "funciones.h"
#include <algorithm>
#include <random>

#define all(x) begin(x), end(x)

using namespace CGAL;

const int D = 48;

int main() {

    string imgPath = "./CK+48/happy/S010_006_00000014.png";
    CImg<float> A(imgPath.c_str());
    CImg<float> B = A.haar(false, 1);
//     B.display();

    vector<VC<float>> imagenes; // 70%
    vector<VC<float>> queries; // 30%

    ifstream file("rutas");
    vector<string> paths;
    if (file.is_open()) {
        string path;
        while (getline(file, path)) {
            paths.push_back(path);
        }
        file.close();
    }

    auto rng = std::default_random_engine {};
    std::shuffle(std::begin(paths), std::end(paths), rng);
    for (int i = 0; i < paths.size(); ++i) {
        VC<float> vc = VC<float>(paths[i].c_str());
        if (i < floor(paths.size() * 0.7)) {
            imagenes.push_back(vc);
        } else {
            queries.push_back(vc);
        }
    }

    VC<float> query = VC<float>("./CK+48/sadness/S014_002_00000015.png");

    vector< pair< double, VC<float> > > result;

    for (const auto& img : imagenes) {
        double distancia = dist3<float>(img, query);
        result.push_back({distancia, img});
    }

    sort(all(result), [](auto& left, auto& right) {
        return left.first > right.first;
    });

    int k = 5;

    cout << "Displaying " << k << " nearest neighbors...\n";

    for (int i = 0; i < k; ++i) {
        CImg<float> img(result[i].second.getImgPath());
        img.display();
    }

    return 0;
}