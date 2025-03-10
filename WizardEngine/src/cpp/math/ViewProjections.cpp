//
// Created by mecha on 23.09.2021.
//

#include <math/ViewProjections.h>

namespace engine::math {

    void serialize(YAML::Emitter& out, const char* key, const ViewProjection2d& vp) {
        out << YAML::BeginMap;
        out << YAML::Key << key;
        yaml::serialize(out, "name", vp.name);
        serialize(out, "viewMatrix", vp.viewMatrix);
        serialize(out, "orthographicMatrix", vp.orthographicMatrix);
        out << YAML::EndMap;
    }

    void deserialize(const YAML::Node& parent, const char* key, ViewProjection2d& vp) {
        auto root = parent[key];
        if (root) {
            yaml::deserialize(root, "name", vp.name);
            deserialize(root, "viewMatrix", vp.viewMatrix);
            deserialize(root, "orthographicMatrix", vp.orthographicMatrix);
        }
    }

    void serialize(YAML::Emitter& out, const char* key, const ViewProjection3d& vp) {
        out << YAML::BeginMap;
        out << YAML::Key << key;
        yaml::serialize(out, "name", vp.name);
        serialize(out, "viewMatrix", vp.viewMatrix);
        serialize(out, "perspectiveMatrix", vp.perspectiveMatrix);
        out << YAML::EndMap;
    }

    void deserialize(const YAML::Node& parent, const char* key, ViewProjection3d& vp) {
        auto root = parent[key];
        if (root) {
            yaml::deserialize(root, "name", vp.name);
            deserialize(root, "viewMatrix", vp.viewMatrix);
            deserialize(root, "perspectiveMatrix", vp.perspectiveMatrix);
        }
    }

    void ViewProjection2d::apply() {
        orthographicMatrix.apply();
        viewMatrix.apply();
        value = orthographicMatrix.value * viewMatrix.value;
    }

    void ViewProjection3d::apply() {
        perspectiveMatrix.apply();
        viewMatrix.apply();
        value = viewMatrix.value * perspectiveMatrix.value;
    }
}