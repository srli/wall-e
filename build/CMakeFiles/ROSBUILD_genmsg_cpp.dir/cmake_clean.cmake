FILE(REMOVE_RECURSE
  "../msg_gen"
  "../msg_gen"
  "../src/walle/msg"
  "CMakeFiles/ROSBUILD_genmsg_cpp"
  "../msg_gen/cpp/include/walle/gestures.h"
  "../msg_gen/cpp/include/walle/HRI.h"
  "../msg_gen/cpp/include/walle/pointerpos.h"
)

# Per-language clean rules from dependency scanning.
FOREACH(lang)
  INCLUDE(CMakeFiles/ROSBUILD_genmsg_cpp.dir/cmake_clean_${lang}.cmake OPTIONAL)
ENDFOREACH(lang)
