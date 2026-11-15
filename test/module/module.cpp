import glm;

int main() {
    const float pi = glm::pi<float>();
    glm::vec3 vec(3, pi, 3);
    vec = glm::normalize(vec);
    return glm::length(vec) != 1.0f;
}
