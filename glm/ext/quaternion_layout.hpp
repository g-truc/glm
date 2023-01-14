#pragma once
#ifdef GLM_FORCE_QUAT_DATA_XYZW
#define GLM_QUAT_LAYOUT(w, x, y, z) x, y, z, w
#else
#define GLM_QUAT_LAYOUT(w, x, y, z) w, x, y, z
#endif
