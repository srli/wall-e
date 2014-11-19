FILE(REMOVE_RECURSE
  "../msg_gen"
  "../msg_gen"
  "../src/walle/msg"
  "CMakeFiles/ROSBUILD_genmsg_py"
  "../src/walle/msg/__init__.py"
  "../src/walle/msg/_HRI.py"
  "../src/walle/msg/_pointerpos.py"
)

# Per-language clean rules from dependency scanning.
FOREACH(lang)
  INCLUDE(CMakeFiles/ROSBUILD_genmsg_py.dir/cmake_clean_${lang}.cmake OPTIONAL)
ENDFOREACH(lang)
