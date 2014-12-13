FILE(REMOVE_RECURSE
  "../msg_gen"
  "../msg_gen"
  "../src/walle/msg"
  "CMakeFiles/ROSBUILD_genmsg_lisp"
  "../msg_gen/lisp/gestures.lisp"
  "../msg_gen/lisp/_package.lisp"
  "../msg_gen/lisp/_package_gestures.lisp"
  "../msg_gen/lisp/HRI.lisp"
  "../msg_gen/lisp/_package.lisp"
  "../msg_gen/lisp/_package_HRI.lisp"
  "../msg_gen/lisp/pointerpos.lisp"
  "../msg_gen/lisp/_package.lisp"
  "../msg_gen/lisp/_package_pointerpos.lisp"
)

# Per-language clean rules from dependency scanning.
FOREACH(lang)
  INCLUDE(CMakeFiles/ROSBUILD_genmsg_lisp.dir/cmake_clean_${lang}.cmake OPTIONAL)
ENDFOREACH(lang)
