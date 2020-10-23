load("@rules_cc//cc:defs.bzl", "cc_library")

cc_library(
    name = "glm",
    srcs = glob(["glm/**/*.cpp"]),
    hdrs = glob([
        "glm/**/*.hpp",
        "glm/**/*.h",
        "glm/**/*.inl",
    ]),
    includes = ["."],
    visibility = ["//visibility:public"],
)
