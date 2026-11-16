import std;
import glm;

int main() {
    int errors = 0;
    const float pi = glm::pi<float>();
    glm::vec3 vec(3, pi, 3);
    vec = glm::normalize(vec);
    errors += !(glm::length(vec) == 1.0f);

#ifdef GLM_ENABLE_EXPERIMENTAL
    std::unordered_set<glm::vec3> unique_vectors;
    unique_vectors.insert(glm::vec3(1.0f, 2.0f, 3.0f));
    unique_vectors.insert(glm::vec3(4.0f, 5.0f, 6.0f));
    unique_vectors.insert(glm::vec3(1.0f, 2.0f, 3.0f));
    errors += !(unique_vectors.size() == 2);
    errors += !(unique_vectors.contains(glm::vec3(4.0f, 5.0f, 6.0f)));
#endif

    return errors;
}
