#!lua
conan_build_type = "Release"
conan_arch = "x86_64"

conan_includedirs = {"E:/conan/fmt/4.1.0/bincrafters/stable/package/6cc50b139b9c3d27b3e9042d5f5372d327b3a9f7/include",
"E:/.conan/806h2xgc/1/date_time/include",
"E:/.conan/806h2xgc/1/locale/include",
"E:/.conan/806h2xgc/1/pool/include",
"E:/.conan/806h2xgc/1/serialization/include",
"E:/.conan/806h2xgc/1/spirit/include",
"E:/.conan/806h2xgc/1/thread/include",
"E:/.conan/gko38959/1/algorithm/include",
"E:/.conan/hvtld5f2/1/chrono/include",
"E:/.conan/8borfk1v/1/endian/include",
"E:/.conan/40t5_75t/1/filesystem/include",
"E:/.conan/q68x3zf3/1/foreach/include",
"E:/.conan/g8ofn5t8/1/iostreams/include",
"E:/.conan/wdeizfcz/1/phoenix/include",
"E:/.conan/1jtx4007/1/tokenizer/include",
"E:/.conan/29l94jiw/1/tti/include",
"E:/.conan/ni7yhr7o/1/variant/include",
"E:/.conan/h2_jl_0v/1/exception/include",
"E:/.conan/8s7pweg0/1/io/include",
"E:/.conan/83xncg1_/1/proto/include",
"E:/.conan/bk5jk9sp/1/random/include",
"E:/.conan/cb132ypo/1/ratio/include",
"E:/.conan/hay1udvk/1/unordered/include",
"E:/.conan/xbnylmvy/1/rational/include",
"E:/.conan/6b3axx5_/1/system/include",
"E:/.conan/pf5tnzwe/1/lexical_cast/include",
"E:/.conan/pf5tnzwe/1/math/include",
"E:/.conan/xcq7pd25/1/winapi/include",
"E:/.conan/x_60o9zm/1/atomic/include",
"E:/.conan/ao8dnd5g/1/container/include",
"E:/.conan/s_eksdf6/1/lambda/include",
"E:/.conan/5j6ybd9x/1/range/include",
"E:/.conan/sp7_ljql/1/array/include",
"E:/.conan/q62or2g1/1/intrusive/include",
"E:/.conan/9v_rq2n7/1/numeric_conversion/include",
"E:/.conan/21r5xgmw/1/regex/include",
"E:/.conan/q_lny750/1/tuple/include",
"E:/.conan/dqne1cw1/1/concept_check/include",
"E:/.conan/dqne1cw1/1/conversion/include",
"E:/.conan/dqne1cw1/1/detail/include",
"E:/.conan/dqne1cw1/1/function/include",
"E:/.conan/dqne1cw1/1/function_types/include",
"E:/.conan/dqne1cw1/1/functional/include",
"E:/.conan/dqne1cw1/1/fusion/include",
"E:/.conan/dqne1cw1/1/iterator/include",
"E:/.conan/dqne1cw1/1/mpl/include",
"E:/.conan/dqne1cw1/1/optional/include",
"E:/.conan/dqne1cw1/1/type_index/include",
"E:/.conan/dqne1cw1/1/typeof/include",
"E:/.conan/dqne1cw1/1/utility/include",
"E:/.conan/6rf6awg7/1/bind/include",
"E:/.conan/5ab071fs/1/integer/include",
"E:/.conan/ev1g1kcb/1/preprocessor/include",
"E:/.conan/p_zak5zq/1/smart_ptr/include",
"E:/.conan/utxnqzqr/1/move/include",
"E:/.conan/03obyp57/1/predef/include",
"E:/.conan/9khyzaae/1/throw_exception/include",
"E:/.conan/lqum5pis/1/type_traits/include",
"E:/.conan/jueckpqg/1/core/include",
"E:/.conan/tsssljru/1/static_assert/include",
"E:/.conan/xf7qytkd/1/assert/include",
"E:/.conan/b7h8j8lo/1/config/include"}
conan_libdirs = {"E:/.conan/6jnjcwmu/1/spirit/lib",
"E:/conan/fmt/4.1.0/bincrafters/stable/package/6cc50b139b9c3d27b3e9042d5f5372d327b3a9f7/lib",
"E:/.conan/806h2xgc/1/date_time/lib",
"E:/.conan/806h2xgc/1/locale/lib",
"E:/.conan/806h2xgc/1/serialization/lib",
"E:/.conan/806h2xgc/1/thread/lib",
"E:/.conan/gko38959/1/algorithm/lib",
"E:/.conan/hvtld5f2/1/chrono/lib",
"E:/.conan/8borfk1v/1/endian/lib",
"E:/.conan/40t5_75t/1/filesystem/lib",
"E:/.conan/q68x3zf3/1/foreach/lib",
"E:/.conan/g8ofn5t8/1/iostreams/lib",
"E:/.conan/wdeizfcz/1/phoenix/lib",
"E:/.conan/1jtx4007/1/tokenizer/lib",
"E:/.conan/29l94jiw/1/tti/lib",
"E:/.conan/ni7yhr7o/1/variant/lib",
"E:/.conan/h2_jl_0v/1/exception/lib",
"E:/.conan/8s7pweg0/1/io/lib",
"E:/.conan/83xncg1_/1/proto/lib",
"E:/.conan/bk5jk9sp/1/random/lib",
"E:/.conan/cb132ypo/1/ratio/lib",
"E:/.conan/hay1udvk/1/unordered/lib",
"E:/.conan/xbnylmvy/1/rational/lib",
"E:/.conan/6b3axx5_/1/system/lib",
"E:/.conan/pf5tnzwe/1/math/lib",
"E:/.conan/xcq7pd25/1/winapi/lib",
"E:/.conan/x_60o9zm/1/atomic/lib",
"E:/.conan/ao8dnd5g/1/container/lib",
"E:/.conan/s_eksdf6/1/lambda/lib",
"E:/.conan/5j6ybd9x/1/range/lib",
"E:/.conan/sp7_ljql/1/array/lib",
"E:/.conan/q62or2g1/1/intrusive/lib",
"E:/.conan/9v_rq2n7/1/numeric_conversion/lib",
"E:/.conan/21r5xgmw/1/regex/lib",
"E:/.conan/q_lny750/1/tuple/lib",
"E:/.conan/6rf6awg7/1/bind/lib",
"E:/.conan/5ab071fs/1/integer/lib",
"E:/.conan/ev1g1kcb/1/preprocessor/lib",
"E:/.conan/p_zak5zq/1/smart_ptr/lib",
"E:/.conan/utxnqzqr/1/move/lib",
"E:/.conan/03obyp57/1/predef/lib",
"E:/.conan/9khyzaae/1/throw_exception/lib",
"E:/.conan/lqum5pis/1/type_traits/lib",
"E:/.conan/jueckpqg/1/core/lib",
"E:/.conan/tsssljru/1/static_assert/lib",
"E:/.conan/xf7qytkd/1/assert/lib",
"E:/.conan/b7h8j8lo/1/config/lib"}
conan_bindirs = {"E:/.conan/6jnjcwmu/1/spirit/lib",
"E:/.conan/806h2xgc/1/date_time/lib",
"E:/.conan/806h2xgc/1/locale/lib",
"E:/.conan/806h2xgc/1/serialization/lib",
"E:/.conan/806h2xgc/1/thread/lib",
"E:/.conan/gko38959/1/algorithm/lib",
"E:/.conan/hvtld5f2/1/chrono/lib",
"E:/.conan/8borfk1v/1/endian/lib",
"E:/.conan/40t5_75t/1/filesystem/lib",
"E:/.conan/q68x3zf3/1/foreach/lib",
"E:/.conan/g8ofn5t8/1/iostreams/lib",
"E:/.conan/wdeizfcz/1/phoenix/lib",
"E:/.conan/1jtx4007/1/tokenizer/lib",
"E:/.conan/29l94jiw/1/tti/lib",
"E:/.conan/ni7yhr7o/1/variant/lib",
"E:/.conan/h2_jl_0v/1/exception/lib",
"E:/.conan/8s7pweg0/1/io/lib",
"E:/.conan/83xncg1_/1/proto/lib",
"E:/.conan/bk5jk9sp/1/random/lib",
"E:/.conan/cb132ypo/1/ratio/lib",
"E:/.conan/hay1udvk/1/unordered/lib",
"E:/.conan/xbnylmvy/1/rational/lib",
"E:/.conan/6b3axx5_/1/system/lib",
"E:/.conan/pf5tnzwe/1/math/lib",
"E:/.conan/xcq7pd25/1/winapi/lib",
"E:/.conan/x_60o9zm/1/atomic/lib",
"E:/.conan/ao8dnd5g/1/container/lib",
"E:/.conan/s_eksdf6/1/lambda/lib",
"E:/.conan/5j6ybd9x/1/range/lib",
"E:/.conan/sp7_ljql/1/array/lib",
"E:/.conan/q62or2g1/1/intrusive/lib",
"E:/.conan/9v_rq2n7/1/numeric_conversion/lib",
"E:/.conan/21r5xgmw/1/regex/lib",
"E:/.conan/q_lny750/1/tuple/lib",
"E:/.conan/6rf6awg7/1/bind/lib",
"E:/.conan/5ab071fs/1/integer/lib",
"E:/.conan/ev1g1kcb/1/preprocessor/lib",
"E:/.conan/p_zak5zq/1/smart_ptr/lib",
"E:/.conan/utxnqzqr/1/move/lib",
"E:/.conan/03obyp57/1/predef/lib",
"E:/.conan/9khyzaae/1/throw_exception/lib",
"E:/.conan/lqum5pis/1/type_traits/lib",
"E:/.conan/jueckpqg/1/core/lib",
"E:/.conan/tsssljru/1/static_assert/lib",
"E:/.conan/xf7qytkd/1/assert/lib",
"E:/.conan/b7h8j8lo/1/config/lib"}
conan_libs = {"fmt", "libboost_chrono", "libboost_filesystem", "libboost_iostreams", "libboost_exception", "libboost_random", "libboost_math_c99", "libboost_math_c99f", "libboost_math_c99l", "libboost_math_tr1", "libboost_math_tr1f", "libboost_math_tr1l", "libboost_system", "libboost_atomic", "libboost_container", "libboost_regex"}
conan_cppdefines = {"BOOST_ALL_NO_LIB=1"}
conan_cppflags = {}
conan_cflags = {}
conan_sharedlinkflags = {}
conan_exelinkflags = {}

conan_includedirs_boost_spirit = {}
conan_libdirs_boost_spirit = {"E:/.conan/6jnjcwmu/1/spirit/lib"}
conan_bindirs_boost_spirit = {"E:/.conan/6jnjcwmu/1/spirit/lib"}
conan_libs_boost_spirit = {}
conan_cppdefines_boost_spirit = {"BOOST_ALL_NO_LIB=1"}
conan_cppflags_boost_spirit = {}
conan_cflags_boost_spirit = {}
conan_sharedlinkflags_boost_spirit = {}
conan_exelinkflags_boost_spirit = {}
conan_rootpath_boost_spirit = "E:/.conan/6jnjcwmu/1"

conan_includedirs_fmt = {"E:/conan/fmt/4.1.0/bincrafters/stable/package/6cc50b139b9c3d27b3e9042d5f5372d327b3a9f7/include"}
conan_libdirs_fmt = {"E:/conan/fmt/4.1.0/bincrafters/stable/package/6cc50b139b9c3d27b3e9042d5f5372d327b3a9f7/lib"}
conan_bindirs_fmt = {}
conan_libs_fmt = {"fmt"}
conan_cppdefines_fmt = {}
conan_cppflags_fmt = {}
conan_cflags_fmt = {}
conan_sharedlinkflags_fmt = {}
conan_exelinkflags_fmt = {}
conan_rootpath_fmt = "E:/conan/fmt/4.1.0/bincrafters/stable/package/6cc50b139b9c3d27b3e9042d5f5372d327b3a9f7"

conan_includedirs_premake_generator = {}
conan_libdirs_premake_generator = {}
conan_bindirs_premake_generator = {}
conan_libs_premake_generator = {}
conan_cppdefines_premake_generator = {}
conan_cppflags_premake_generator = {}
conan_cflags_premake_generator = {}
conan_sharedlinkflags_premake_generator = {}
conan_exelinkflags_premake_generator = {}
conan_rootpath_premake_generator = "E:/conan/premake_generator/master/enhex/stable/package/5ab84d6acfe1f23c4fae0ab88f26e3a396351ac9"

conan_includedirs_boost_level11group = {"E:/.conan/806h2xgc/1/date_time/include",
"E:/.conan/806h2xgc/1/locale/include",
"E:/.conan/806h2xgc/1/pool/include",
"E:/.conan/806h2xgc/1/serialization/include",
"E:/.conan/806h2xgc/1/spirit/include",
"E:/.conan/806h2xgc/1/thread/include"}
conan_libdirs_boost_level11group = {"E:/.conan/806h2xgc/1/date_time/lib",
"E:/.conan/806h2xgc/1/locale/lib",
"E:/.conan/806h2xgc/1/serialization/lib",
"E:/.conan/806h2xgc/1/thread/lib"}
conan_bindirs_boost_level11group = {"E:/.conan/806h2xgc/1/date_time/lib",
"E:/.conan/806h2xgc/1/locale/lib",
"E:/.conan/806h2xgc/1/serialization/lib",
"E:/.conan/806h2xgc/1/thread/lib"}
conan_libs_boost_level11group = {}
conan_cppdefines_boost_level11group = {"BOOST_ALL_NO_LIB=1"}
conan_cppflags_boost_level11group = {}
conan_cflags_boost_level11group = {}
conan_sharedlinkflags_boost_level11group = {}
conan_exelinkflags_boost_level11group = {}
conan_rootpath_boost_level11group = "E:/.conan/806h2xgc/1"

conan_includedirs_boost_algorithm = {"E:/.conan/gko38959/1/algorithm/include"}
conan_libdirs_boost_algorithm = {"E:/.conan/gko38959/1/algorithm/lib"}
conan_bindirs_boost_algorithm = {"E:/.conan/gko38959/1/algorithm/lib"}
conan_libs_boost_algorithm = {}
conan_cppdefines_boost_algorithm = {"BOOST_ALL_NO_LIB=1"}
conan_cppflags_boost_algorithm = {}
conan_cflags_boost_algorithm = {}
conan_sharedlinkflags_boost_algorithm = {}
conan_exelinkflags_boost_algorithm = {}
conan_rootpath_boost_algorithm = "E:/.conan/gko38959/1"

conan_includedirs_boost_chrono = {"E:/.conan/hvtld5f2/1/chrono/include"}
conan_libdirs_boost_chrono = {"E:/.conan/hvtld5f2/1/chrono/lib"}
conan_bindirs_boost_chrono = {"E:/.conan/hvtld5f2/1/chrono/lib"}
conan_libs_boost_chrono = {"libboost_chrono"}
conan_cppdefines_boost_chrono = {"BOOST_ALL_NO_LIB=1"}
conan_cppflags_boost_chrono = {}
conan_cflags_boost_chrono = {}
conan_sharedlinkflags_boost_chrono = {}
conan_exelinkflags_boost_chrono = {}
conan_rootpath_boost_chrono = "E:/.conan/hvtld5f2/1"

conan_includedirs_boost_endian = {"E:/.conan/8borfk1v/1/endian/include"}
conan_libdirs_boost_endian = {"E:/.conan/8borfk1v/1/endian/lib"}
conan_bindirs_boost_endian = {"E:/.conan/8borfk1v/1/endian/lib"}
conan_libs_boost_endian = {}
conan_cppdefines_boost_endian = {"BOOST_ALL_NO_LIB=1"}
conan_cppflags_boost_endian = {}
conan_cflags_boost_endian = {}
conan_sharedlinkflags_boost_endian = {}
conan_exelinkflags_boost_endian = {}
conan_rootpath_boost_endian = "E:/.conan/8borfk1v/1"

conan_includedirs_boost_filesystem = {"E:/.conan/40t5_75t/1/filesystem/include"}
conan_libdirs_boost_filesystem = {"E:/.conan/40t5_75t/1/filesystem/lib"}
conan_bindirs_boost_filesystem = {"E:/.conan/40t5_75t/1/filesystem/lib"}
conan_libs_boost_filesystem = {"libboost_filesystem"}
conan_cppdefines_boost_filesystem = {"BOOST_ALL_NO_LIB=1"}
conan_cppflags_boost_filesystem = {}
conan_cflags_boost_filesystem = {}
conan_sharedlinkflags_boost_filesystem = {}
conan_exelinkflags_boost_filesystem = {}
conan_rootpath_boost_filesystem = "E:/.conan/40t5_75t/1"

conan_includedirs_boost_foreach = {"E:/.conan/q68x3zf3/1/foreach/include"}
conan_libdirs_boost_foreach = {"E:/.conan/q68x3zf3/1/foreach/lib"}
conan_bindirs_boost_foreach = {"E:/.conan/q68x3zf3/1/foreach/lib"}
conan_libs_boost_foreach = {}
conan_cppdefines_boost_foreach = {"BOOST_ALL_NO_LIB=1"}
conan_cppflags_boost_foreach = {}
conan_cflags_boost_foreach = {}
conan_sharedlinkflags_boost_foreach = {}
conan_exelinkflags_boost_foreach = {}
conan_rootpath_boost_foreach = "E:/.conan/q68x3zf3/1"

conan_includedirs_boost_iostreams = {"E:/.conan/g8ofn5t8/1/iostreams/include"}
conan_libdirs_boost_iostreams = {"E:/.conan/g8ofn5t8/1/iostreams/lib"}
conan_bindirs_boost_iostreams = {"E:/.conan/g8ofn5t8/1/iostreams/lib"}
conan_libs_boost_iostreams = {"libboost_iostreams"}
conan_cppdefines_boost_iostreams = {"BOOST_ALL_NO_LIB=1"}
conan_cppflags_boost_iostreams = {}
conan_cflags_boost_iostreams = {}
conan_sharedlinkflags_boost_iostreams = {}
conan_exelinkflags_boost_iostreams = {}
conan_rootpath_boost_iostreams = "E:/.conan/g8ofn5t8/1"

conan_includedirs_boost_lexical_cast = {}
conan_libdirs_boost_lexical_cast = {}
conan_bindirs_boost_lexical_cast = {}
conan_libs_boost_lexical_cast = {}
conan_cppdefines_boost_lexical_cast = {"BOOST_ALL_NO_LIB=1"}
conan_cppflags_boost_lexical_cast = {}
conan_cflags_boost_lexical_cast = {}
conan_sharedlinkflags_boost_lexical_cast = {}
conan_exelinkflags_boost_lexical_cast = {}
conan_rootpath_boost_lexical_cast = "E:/.conan/7wanqdtq/1"

conan_includedirs_boost_phoenix = {"E:/.conan/wdeizfcz/1/phoenix/include"}
conan_libdirs_boost_phoenix = {"E:/.conan/wdeizfcz/1/phoenix/lib"}
conan_bindirs_boost_phoenix = {"E:/.conan/wdeizfcz/1/phoenix/lib"}
conan_libs_boost_phoenix = {}
conan_cppdefines_boost_phoenix = {"BOOST_ALL_NO_LIB=1"}
conan_cppflags_boost_phoenix = {}
conan_cflags_boost_phoenix = {}
conan_sharedlinkflags_boost_phoenix = {}
conan_exelinkflags_boost_phoenix = {}
conan_rootpath_boost_phoenix = "E:/.conan/wdeizfcz/1"

conan_includedirs_boost_tokenizer = {"E:/.conan/1jtx4007/1/tokenizer/include"}
conan_libdirs_boost_tokenizer = {"E:/.conan/1jtx4007/1/tokenizer/lib"}
conan_bindirs_boost_tokenizer = {"E:/.conan/1jtx4007/1/tokenizer/lib"}
conan_libs_boost_tokenizer = {}
conan_cppdefines_boost_tokenizer = {"BOOST_ALL_NO_LIB=1"}
conan_cppflags_boost_tokenizer = {}
conan_cflags_boost_tokenizer = {}
conan_sharedlinkflags_boost_tokenizer = {}
conan_exelinkflags_boost_tokenizer = {}
conan_rootpath_boost_tokenizer = "E:/.conan/1jtx4007/1"

conan_includedirs_boost_tti = {"E:/.conan/29l94jiw/1/tti/include"}
conan_libdirs_boost_tti = {"E:/.conan/29l94jiw/1/tti/lib"}
conan_bindirs_boost_tti = {"E:/.conan/29l94jiw/1/tti/lib"}
conan_libs_boost_tti = {}
conan_cppdefines_boost_tti = {"BOOST_ALL_NO_LIB=1"}
conan_cppflags_boost_tti = {}
conan_cflags_boost_tti = {}
conan_sharedlinkflags_boost_tti = {}
conan_exelinkflags_boost_tti = {}
conan_rootpath_boost_tti = "E:/.conan/29l94jiw/1"

conan_includedirs_boost_variant = {"E:/.conan/ni7yhr7o/1/variant/include"}
conan_libdirs_boost_variant = {"E:/.conan/ni7yhr7o/1/variant/lib"}
conan_bindirs_boost_variant = {"E:/.conan/ni7yhr7o/1/variant/lib"}
conan_libs_boost_variant = {}
conan_cppdefines_boost_variant = {"BOOST_ALL_NO_LIB=1"}
conan_cppflags_boost_variant = {}
conan_cflags_boost_variant = {}
conan_sharedlinkflags_boost_variant = {}
conan_exelinkflags_boost_variant = {}
conan_rootpath_boost_variant = "E:/.conan/ni7yhr7o/1"

conan_includedirs_boost_exception = {"E:/.conan/h2_jl_0v/1/exception/include"}
conan_libdirs_boost_exception = {"E:/.conan/h2_jl_0v/1/exception/lib"}
conan_bindirs_boost_exception = {"E:/.conan/h2_jl_0v/1/exception/lib"}
conan_libs_boost_exception = {"libboost_exception"}
conan_cppdefines_boost_exception = {"BOOST_ALL_NO_LIB=1"}
conan_cppflags_boost_exception = {}
conan_cflags_boost_exception = {}
conan_sharedlinkflags_boost_exception = {}
conan_exelinkflags_boost_exception = {}
conan_rootpath_boost_exception = "E:/.conan/h2_jl_0v/1"

conan_includedirs_boost_function_types = {}
conan_libdirs_boost_function_types = {}
conan_bindirs_boost_function_types = {}
conan_libs_boost_function_types = {}
conan_cppdefines_boost_function_types = {"BOOST_ALL_NO_LIB=1"}
conan_cppflags_boost_function_types = {}
conan_cflags_boost_function_types = {}
conan_sharedlinkflags_boost_function_types = {}
conan_exelinkflags_boost_function_types = {}
conan_rootpath_boost_function_types = "E:/.conan/1wrc4u15/1"

conan_includedirs_boost_io = {"E:/.conan/8s7pweg0/1/io/include"}
conan_libdirs_boost_io = {"E:/.conan/8s7pweg0/1/io/lib"}
conan_bindirs_boost_io = {"E:/.conan/8s7pweg0/1/io/lib"}
conan_libs_boost_io = {}
conan_cppdefines_boost_io = {"BOOST_ALL_NO_LIB=1"}
conan_cppflags_boost_io = {}
conan_cflags_boost_io = {}
conan_sharedlinkflags_boost_io = {}
conan_exelinkflags_boost_io = {}
conan_rootpath_boost_io = "E:/.conan/8s7pweg0/1"

conan_includedirs_boost_proto = {"E:/.conan/83xncg1_/1/proto/include"}
conan_libdirs_boost_proto = {"E:/.conan/83xncg1_/1/proto/lib"}
conan_bindirs_boost_proto = {"E:/.conan/83xncg1_/1/proto/lib"}
conan_libs_boost_proto = {}
conan_cppdefines_boost_proto = {"BOOST_ALL_NO_LIB=1"}
conan_cppflags_boost_proto = {}
conan_cflags_boost_proto = {}
conan_sharedlinkflags_boost_proto = {}
conan_exelinkflags_boost_proto = {}
conan_rootpath_boost_proto = "E:/.conan/83xncg1_/1"

conan_includedirs_boost_random = {"E:/.conan/bk5jk9sp/1/random/include"}
conan_libdirs_boost_random = {"E:/.conan/bk5jk9sp/1/random/lib"}
conan_bindirs_boost_random = {"E:/.conan/bk5jk9sp/1/random/lib"}
conan_libs_boost_random = {"libboost_random"}
conan_cppdefines_boost_random = {"BOOST_ALL_NO_LIB=1"}
conan_cppflags_boost_random = {}
conan_cflags_boost_random = {}
conan_sharedlinkflags_boost_random = {}
conan_exelinkflags_boost_random = {}
conan_rootpath_boost_random = "E:/.conan/bk5jk9sp/1"

conan_includedirs_boost_ratio = {"E:/.conan/cb132ypo/1/ratio/include"}
conan_libdirs_boost_ratio = {"E:/.conan/cb132ypo/1/ratio/lib"}
conan_bindirs_boost_ratio = {"E:/.conan/cb132ypo/1/ratio/lib"}
conan_libs_boost_ratio = {}
conan_cppdefines_boost_ratio = {"BOOST_ALL_NO_LIB=1"}
conan_cppflags_boost_ratio = {}
conan_cflags_boost_ratio = {}
conan_sharedlinkflags_boost_ratio = {}
conan_exelinkflags_boost_ratio = {}
conan_rootpath_boost_ratio = "E:/.conan/cb132ypo/1"

conan_includedirs_boost_type_index = {}
conan_libdirs_boost_type_index = {}
conan_bindirs_boost_type_index = {}
conan_libs_boost_type_index = {}
conan_cppdefines_boost_type_index = {"BOOST_ALL_NO_LIB=1"}
conan_cppflags_boost_type_index = {}
conan_cflags_boost_type_index = {}
conan_sharedlinkflags_boost_type_index = {}
conan_exelinkflags_boost_type_index = {}
conan_rootpath_boost_type_index = "E:/.conan/cjwda3o0/1"

conan_includedirs_boost_unordered = {"E:/.conan/hay1udvk/1/unordered/include"}
conan_libdirs_boost_unordered = {"E:/.conan/hay1udvk/1/unordered/lib"}
conan_bindirs_boost_unordered = {"E:/.conan/hay1udvk/1/unordered/lib"}
conan_libs_boost_unordered = {}
conan_cppdefines_boost_unordered = {"BOOST_ALL_NO_LIB=1"}
conan_cppflags_boost_unordered = {}
conan_cflags_boost_unordered = {}
conan_sharedlinkflags_boost_unordered = {}
conan_exelinkflags_boost_unordered = {}
conan_rootpath_boost_unordered = "E:/.conan/hay1udvk/1"

conan_includedirs_boost_math = {}
conan_libdirs_boost_math = {}
conan_bindirs_boost_math = {}
conan_libs_boost_math = {"libboost_math_c99", "libboost_math_c99f", "libboost_math_c99l", "libboost_math_tr1", "libboost_math_tr1f", "libboost_math_tr1l"}
conan_cppdefines_boost_math = {"BOOST_ALL_NO_LIB=1"}
conan_cppflags_boost_math = {}
conan_cflags_boost_math = {}
conan_sharedlinkflags_boost_math = {}
conan_exelinkflags_boost_math = {}
conan_rootpath_boost_math = "E:/.conan/l69h6l4t/1"

conan_includedirs_boost_rational = {"E:/.conan/xbnylmvy/1/rational/include"}
conan_libdirs_boost_rational = {"E:/.conan/xbnylmvy/1/rational/lib"}
conan_bindirs_boost_rational = {"E:/.conan/xbnylmvy/1/rational/lib"}
conan_libs_boost_rational = {}
conan_cppdefines_boost_rational = {"BOOST_ALL_NO_LIB=1"}
conan_cppflags_boost_rational = {}
conan_cflags_boost_rational = {}
conan_sharedlinkflags_boost_rational = {}
conan_exelinkflags_boost_rational = {}
conan_rootpath_boost_rational = "E:/.conan/xbnylmvy/1"

conan_includedirs_boost_system = {"E:/.conan/6b3axx5_/1/system/include"}
conan_libdirs_boost_system = {"E:/.conan/6b3axx5_/1/system/lib"}
conan_bindirs_boost_system = {"E:/.conan/6b3axx5_/1/system/lib"}
conan_libs_boost_system = {"libboost_system"}
conan_cppdefines_boost_system = {"BOOST_ALL_NO_LIB=1"}
conan_cppflags_boost_system = {}
conan_cflags_boost_system = {}
conan_sharedlinkflags_boost_system = {}
conan_exelinkflags_boost_system = {}
conan_rootpath_boost_system = "E:/.conan/6b3axx5_/1"

conan_includedirs_boost_typeof = {}
conan_libdirs_boost_typeof = {}
conan_bindirs_boost_typeof = {}
conan_libs_boost_typeof = {}
conan_cppdefines_boost_typeof = {"BOOST_ALL_NO_LIB=1"}
conan_cppflags_boost_typeof = {}
conan_cflags_boost_typeof = {}
conan_sharedlinkflags_boost_typeof = {}
conan_exelinkflags_boost_typeof = {}
conan_rootpath_boost_typeof = "E:/.conan/mep2msag/1"

conan_includedirs_boost_level8group = {"E:/.conan/pf5tnzwe/1/lexical_cast/include",
"E:/.conan/pf5tnzwe/1/math/include"}
conan_libdirs_boost_level8group = {"E:/.conan/pf5tnzwe/1/math/lib"}
conan_bindirs_boost_level8group = {"E:/.conan/pf5tnzwe/1/math/lib"}
conan_libs_boost_level8group = {}
conan_cppdefines_boost_level8group = {"BOOST_ALL_NO_LIB=1"}
conan_cppflags_boost_level8group = {}
conan_cflags_boost_level8group = {}
conan_sharedlinkflags_boost_level8group = {}
conan_exelinkflags_boost_level8group = {}
conan_rootpath_boost_level8group = "E:/.conan/pf5tnzwe/1"

conan_includedirs_boost_winapi = {"E:/.conan/xcq7pd25/1/winapi/include"}
conan_libdirs_boost_winapi = {"E:/.conan/xcq7pd25/1/winapi/lib"}
conan_bindirs_boost_winapi = {"E:/.conan/xcq7pd25/1/winapi/lib"}
conan_libs_boost_winapi = {}
conan_cppdefines_boost_winapi = {"BOOST_ALL_NO_LIB=1"}
conan_cppflags_boost_winapi = {}
conan_cflags_boost_winapi = {}
conan_sharedlinkflags_boost_winapi = {}
conan_exelinkflags_boost_winapi = {}
conan_rootpath_boost_winapi = "E:/.conan/xcq7pd25/1"

conan_includedirs_boost_atomic = {"E:/.conan/x_60o9zm/1/atomic/include"}
conan_libdirs_boost_atomic = {"E:/.conan/x_60o9zm/1/atomic/lib"}
conan_bindirs_boost_atomic = {"E:/.conan/x_60o9zm/1/atomic/lib"}
conan_libs_boost_atomic = {"libboost_atomic"}
conan_cppdefines_boost_atomic = {"BOOST_ALL_NO_LIB=1"}
conan_cppflags_boost_atomic = {}
conan_cflags_boost_atomic = {}
conan_sharedlinkflags_boost_atomic = {}
conan_exelinkflags_boost_atomic = {}
conan_rootpath_boost_atomic = "E:/.conan/x_60o9zm/1"

conan_includedirs_boost_container = {"E:/.conan/ao8dnd5g/1/container/include"}
conan_libdirs_boost_container = {"E:/.conan/ao8dnd5g/1/container/lib"}
conan_bindirs_boost_container = {"E:/.conan/ao8dnd5g/1/container/lib"}
conan_libs_boost_container = {"libboost_container"}
conan_cppdefines_boost_container = {"BOOST_ALL_NO_LIB=1"}
conan_cppflags_boost_container = {}
conan_cflags_boost_container = {}
conan_sharedlinkflags_boost_container = {}
conan_exelinkflags_boost_container = {}
conan_rootpath_boost_container = "E:/.conan/ao8dnd5g/1"

conan_includedirs_boost_function = {}
conan_libdirs_boost_function = {}
conan_bindirs_boost_function = {}
conan_libs_boost_function = {}
conan_cppdefines_boost_function = {"BOOST_ALL_NO_LIB=1"}
conan_cppflags_boost_function = {}
conan_cflags_boost_function = {}
conan_sharedlinkflags_boost_function = {}
conan_exelinkflags_boost_function = {}
conan_rootpath_boost_function = "E:/.conan/ukk4mz73/1"

conan_includedirs_boost_fusion = {}
conan_libdirs_boost_fusion = {}
conan_bindirs_boost_fusion = {}
conan_libs_boost_fusion = {}
conan_cppdefines_boost_fusion = {"BOOST_ALL_NO_LIB=1"}
conan_cppflags_boost_fusion = {}
conan_cflags_boost_fusion = {}
conan_sharedlinkflags_boost_fusion = {}
conan_exelinkflags_boost_fusion = {}
conan_rootpath_boost_fusion = "E:/.conan/ajo0bf9q/1"

conan_includedirs_boost_lambda = {"E:/.conan/s_eksdf6/1/lambda/include"}
conan_libdirs_boost_lambda = {"E:/.conan/s_eksdf6/1/lambda/lib"}
conan_bindirs_boost_lambda = {"E:/.conan/s_eksdf6/1/lambda/lib"}
conan_libs_boost_lambda = {}
conan_cppdefines_boost_lambda = {"BOOST_ALL_NO_LIB=1"}
conan_cppflags_boost_lambda = {}
conan_cflags_boost_lambda = {}
conan_sharedlinkflags_boost_lambda = {}
conan_exelinkflags_boost_lambda = {}
conan_rootpath_boost_lambda = "E:/.conan/s_eksdf6/1"

conan_includedirs_boost_range = {"E:/.conan/5j6ybd9x/1/range/include"}
conan_libdirs_boost_range = {"E:/.conan/5j6ybd9x/1/range/lib"}
conan_bindirs_boost_range = {"E:/.conan/5j6ybd9x/1/range/lib"}
conan_libs_boost_range = {}
conan_cppdefines_boost_range = {"BOOST_ALL_NO_LIB=1"}
conan_cppflags_boost_range = {}
conan_cflags_boost_range = {}
conan_sharedlinkflags_boost_range = {}
conan_exelinkflags_boost_range = {}
conan_rootpath_boost_range = "E:/.conan/5j6ybd9x/1"

conan_includedirs_boost_array = {"E:/.conan/sp7_ljql/1/array/include"}
conan_libdirs_boost_array = {"E:/.conan/sp7_ljql/1/array/lib"}
conan_bindirs_boost_array = {"E:/.conan/sp7_ljql/1/array/lib"}
conan_libs_boost_array = {}
conan_cppdefines_boost_array = {"BOOST_ALL_NO_LIB=1"}
conan_cppflags_boost_array = {}
conan_cflags_boost_array = {}
conan_sharedlinkflags_boost_array = {}
conan_exelinkflags_boost_array = {}
conan_rootpath_boost_array = "E:/.conan/sp7_ljql/1"

conan_includedirs_boost_detail = {}
conan_libdirs_boost_detail = {}
conan_bindirs_boost_detail = {}
conan_libs_boost_detail = {}
conan_cppdefines_boost_detail = {"BOOST_ALL_NO_LIB=1"}
conan_cppflags_boost_detail = {}
conan_cflags_boost_detail = {}
conan_sharedlinkflags_boost_detail = {}
conan_exelinkflags_boost_detail = {}
conan_rootpath_boost_detail = "E:/.conan/37r4t_ts/1"

conan_includedirs_boost_intrusive = {"E:/.conan/q62or2g1/1/intrusive/include"}
conan_libdirs_boost_intrusive = {"E:/.conan/q62or2g1/1/intrusive/lib"}
conan_bindirs_boost_intrusive = {"E:/.conan/q62or2g1/1/intrusive/lib"}
conan_libs_boost_intrusive = {}
conan_cppdefines_boost_intrusive = {"BOOST_ALL_NO_LIB=1"}
conan_cppflags_boost_intrusive = {}
conan_cflags_boost_intrusive = {}
conan_sharedlinkflags_boost_intrusive = {}
conan_exelinkflags_boost_intrusive = {}
conan_rootpath_boost_intrusive = "E:/.conan/q62or2g1/1"

conan_includedirs_boost_numeric_conversion = {"E:/.conan/9v_rq2n7/1/numeric_conversion/include"}
conan_libdirs_boost_numeric_conversion = {"E:/.conan/9v_rq2n7/1/numeric_conversion/lib"}
conan_bindirs_boost_numeric_conversion = {"E:/.conan/9v_rq2n7/1/numeric_conversion/lib"}
conan_libs_boost_numeric_conversion = {}
conan_cppdefines_boost_numeric_conversion = {"BOOST_ALL_NO_LIB=1"}
conan_cppflags_boost_numeric_conversion = {}
conan_cflags_boost_numeric_conversion = {}
conan_sharedlinkflags_boost_numeric_conversion = {}
conan_exelinkflags_boost_numeric_conversion = {}
conan_rootpath_boost_numeric_conversion = "E:/.conan/9v_rq2n7/1"

conan_includedirs_boost_optional = {}
conan_libdirs_boost_optional = {}
conan_bindirs_boost_optional = {}
conan_libs_boost_optional = {}
conan_cppdefines_boost_optional = {"BOOST_ALL_NO_LIB=1"}
conan_cppflags_boost_optional = {}
conan_cflags_boost_optional = {}
conan_sharedlinkflags_boost_optional = {}
conan_exelinkflags_boost_optional = {}
conan_rootpath_boost_optional = "E:/.conan/fh1g8dks/1"

conan_includedirs_boost_regex = {"E:/.conan/21r5xgmw/1/regex/include"}
conan_libdirs_boost_regex = {"E:/.conan/21r5xgmw/1/regex/lib"}
conan_bindirs_boost_regex = {"E:/.conan/21r5xgmw/1/regex/lib"}
conan_libs_boost_regex = {"libboost_regex"}
conan_cppdefines_boost_regex = {"BOOST_ALL_NO_LIB=1"}
conan_cppflags_boost_regex = {}
conan_cflags_boost_regex = {}
conan_sharedlinkflags_boost_regex = {}
conan_exelinkflags_boost_regex = {}
conan_rootpath_boost_regex = "E:/.conan/21r5xgmw/1"

conan_includedirs_boost_tuple = {"E:/.conan/q_lny750/1/tuple/include"}
conan_libdirs_boost_tuple = {"E:/.conan/q_lny750/1/tuple/lib"}
conan_bindirs_boost_tuple = {"E:/.conan/q_lny750/1/tuple/lib"}
conan_libs_boost_tuple = {}
conan_cppdefines_boost_tuple = {"BOOST_ALL_NO_LIB=1"}
conan_cppflags_boost_tuple = {}
conan_cflags_boost_tuple = {}
conan_sharedlinkflags_boost_tuple = {}
conan_exelinkflags_boost_tuple = {}
conan_rootpath_boost_tuple = "E:/.conan/q_lny750/1"

conan_includedirs_boost_utility = {}
conan_libdirs_boost_utility = {}
conan_bindirs_boost_utility = {}
conan_libs_boost_utility = {}
conan_cppdefines_boost_utility = {"BOOST_ALL_NO_LIB=1"}
conan_cppflags_boost_utility = {}
conan_cflags_boost_utility = {}
conan_sharedlinkflags_boost_utility = {}
conan_exelinkflags_boost_utility = {}
conan_rootpath_boost_utility = "E:/.conan/wadtc3s0/1"

conan_includedirs_boost_concept_check = {}
conan_libdirs_boost_concept_check = {}
conan_bindirs_boost_concept_check = {}
conan_libs_boost_concept_check = {}
conan_cppdefines_boost_concept_check = {"BOOST_ALL_NO_LIB=1"}
conan_cppflags_boost_concept_check = {}
conan_cflags_boost_concept_check = {}
conan_sharedlinkflags_boost_concept_check = {}
conan_exelinkflags_boost_concept_check = {}
conan_rootpath_boost_concept_check = "E:/.conan/t61k6tuz/1"

conan_includedirs_boost_conversion = {}
conan_libdirs_boost_conversion = {}
conan_bindirs_boost_conversion = {}
conan_libs_boost_conversion = {}
conan_cppdefines_boost_conversion = {"BOOST_ALL_NO_LIB=1"}
conan_cppflags_boost_conversion = {}
conan_cflags_boost_conversion = {}
conan_sharedlinkflags_boost_conversion = {}
conan_exelinkflags_boost_conversion = {}
conan_rootpath_boost_conversion = "E:/.conan/ikixtre3/1"

conan_includedirs_boost_functional = {}
conan_libdirs_boost_functional = {}
conan_bindirs_boost_functional = {}
conan_libs_boost_functional = {}
conan_cppdefines_boost_functional = {"BOOST_ALL_NO_LIB=1"}
conan_cppflags_boost_functional = {}
conan_cflags_boost_functional = {}
conan_sharedlinkflags_boost_functional = {}
conan_exelinkflags_boost_functional = {}
conan_rootpath_boost_functional = "E:/.conan/9u2tmu_l/1"

conan_includedirs_boost_iterator = {}
conan_libdirs_boost_iterator = {}
conan_bindirs_boost_iterator = {}
conan_libs_boost_iterator = {}
conan_cppdefines_boost_iterator = {"BOOST_ALL_NO_LIB=1"}
conan_cppflags_boost_iterator = {}
conan_cflags_boost_iterator = {}
conan_sharedlinkflags_boost_iterator = {}
conan_exelinkflags_boost_iterator = {}
conan_rootpath_boost_iterator = "E:/.conan/xnqd5_6y/1"

conan_includedirs_boost_mpl = {}
conan_libdirs_boost_mpl = {}
conan_bindirs_boost_mpl = {}
conan_libs_boost_mpl = {}
conan_cppdefines_boost_mpl = {"BOOST_ALL_NO_LIB=1"}
conan_cppflags_boost_mpl = {}
conan_cflags_boost_mpl = {}
conan_sharedlinkflags_boost_mpl = {}
conan_exelinkflags_boost_mpl = {}
conan_rootpath_boost_mpl = "E:/.conan/1mfg0usd/1"

conan_includedirs_boost_level5group = {"E:/.conan/dqne1cw1/1/concept_check/include",
"E:/.conan/dqne1cw1/1/conversion/include",
"E:/.conan/dqne1cw1/1/detail/include",
"E:/.conan/dqne1cw1/1/function/include",
"E:/.conan/dqne1cw1/1/function_types/include",
"E:/.conan/dqne1cw1/1/functional/include",
"E:/.conan/dqne1cw1/1/fusion/include",
"E:/.conan/dqne1cw1/1/iterator/include",
"E:/.conan/dqne1cw1/1/mpl/include",
"E:/.conan/dqne1cw1/1/optional/include",
"E:/.conan/dqne1cw1/1/type_index/include",
"E:/.conan/dqne1cw1/1/typeof/include",
"E:/.conan/dqne1cw1/1/utility/include"}
conan_libdirs_boost_level5group = {}
conan_bindirs_boost_level5group = {}
conan_libs_boost_level5group = {}
conan_cppdefines_boost_level5group = {"BOOST_ALL_NO_LIB=1"}
conan_cppflags_boost_level5group = {}
conan_cflags_boost_level5group = {}
conan_sharedlinkflags_boost_level5group = {}
conan_exelinkflags_boost_level5group = {}
conan_rootpath_boost_level5group = "E:/.conan/dqne1cw1/1"

conan_includedirs_boost_bind = {"E:/.conan/6rf6awg7/1/bind/include"}
conan_libdirs_boost_bind = {"E:/.conan/6rf6awg7/1/bind/lib"}
conan_bindirs_boost_bind = {"E:/.conan/6rf6awg7/1/bind/lib"}
conan_libs_boost_bind = {}
conan_cppdefines_boost_bind = {"BOOST_ALL_NO_LIB=1"}
conan_cppflags_boost_bind = {}
conan_cflags_boost_bind = {}
conan_sharedlinkflags_boost_bind = {}
conan_exelinkflags_boost_bind = {}
conan_rootpath_boost_bind = "E:/.conan/6rf6awg7/1"

conan_includedirs_boost_integer = {"E:/.conan/5ab071fs/1/integer/include"}
conan_libdirs_boost_integer = {"E:/.conan/5ab071fs/1/integer/lib"}
conan_bindirs_boost_integer = {"E:/.conan/5ab071fs/1/integer/lib"}
conan_libs_boost_integer = {}
conan_cppdefines_boost_integer = {"BOOST_ALL_NO_LIB=1"}
conan_cppflags_boost_integer = {}
conan_cflags_boost_integer = {}
conan_sharedlinkflags_boost_integer = {}
conan_exelinkflags_boost_integer = {}
conan_rootpath_boost_integer = "E:/.conan/5ab071fs/1"

conan_includedirs_boost_preprocessor = {"E:/.conan/ev1g1kcb/1/preprocessor/include"}
conan_libdirs_boost_preprocessor = {"E:/.conan/ev1g1kcb/1/preprocessor/lib"}
conan_bindirs_boost_preprocessor = {"E:/.conan/ev1g1kcb/1/preprocessor/lib"}
conan_libs_boost_preprocessor = {}
conan_cppdefines_boost_preprocessor = {"BOOST_ALL_NO_LIB=1"}
conan_cppflags_boost_preprocessor = {}
conan_cflags_boost_preprocessor = {}
conan_sharedlinkflags_boost_preprocessor = {}
conan_exelinkflags_boost_preprocessor = {}
conan_rootpath_boost_preprocessor = "E:/.conan/ev1g1kcb/1"

conan_includedirs_boost_smart_ptr = {"E:/.conan/p_zak5zq/1/smart_ptr/include"}
conan_libdirs_boost_smart_ptr = {"E:/.conan/p_zak5zq/1/smart_ptr/lib"}
conan_bindirs_boost_smart_ptr = {"E:/.conan/p_zak5zq/1/smart_ptr/lib"}
conan_libs_boost_smart_ptr = {}
conan_cppdefines_boost_smart_ptr = {"BOOST_ALL_NO_LIB=1"}
conan_cppflags_boost_smart_ptr = {}
conan_cflags_boost_smart_ptr = {}
conan_sharedlinkflags_boost_smart_ptr = {}
conan_exelinkflags_boost_smart_ptr = {}
conan_rootpath_boost_smart_ptr = "E:/.conan/p_zak5zq/1"

conan_includedirs_boost_move = {"E:/.conan/utxnqzqr/1/move/include"}
conan_libdirs_boost_move = {"E:/.conan/utxnqzqr/1/move/lib"}
conan_bindirs_boost_move = {"E:/.conan/utxnqzqr/1/move/lib"}
conan_libs_boost_move = {}
conan_cppdefines_boost_move = {"BOOST_ALL_NO_LIB=1"}
conan_cppflags_boost_move = {}
conan_cflags_boost_move = {}
conan_sharedlinkflags_boost_move = {}
conan_exelinkflags_boost_move = {}
conan_rootpath_boost_move = "E:/.conan/utxnqzqr/1"

conan_includedirs_boost_predef = {"E:/.conan/03obyp57/1/predef/include"}
conan_libdirs_boost_predef = {"E:/.conan/03obyp57/1/predef/lib"}
conan_bindirs_boost_predef = {"E:/.conan/03obyp57/1/predef/lib"}
conan_libs_boost_predef = {}
conan_cppdefines_boost_predef = {"BOOST_ALL_NO_LIB=1"}
conan_cppflags_boost_predef = {}
conan_cflags_boost_predef = {}
conan_sharedlinkflags_boost_predef = {}
conan_exelinkflags_boost_predef = {}
conan_rootpath_boost_predef = "E:/.conan/03obyp57/1"

conan_includedirs_boost_throw_exception = {"E:/.conan/9khyzaae/1/throw_exception/include"}
conan_libdirs_boost_throw_exception = {"E:/.conan/9khyzaae/1/throw_exception/lib"}
conan_bindirs_boost_throw_exception = {"E:/.conan/9khyzaae/1/throw_exception/lib"}
conan_libs_boost_throw_exception = {}
conan_cppdefines_boost_throw_exception = {"BOOST_ALL_NO_LIB=1"}
conan_cppflags_boost_throw_exception = {}
conan_cflags_boost_throw_exception = {}
conan_sharedlinkflags_boost_throw_exception = {}
conan_exelinkflags_boost_throw_exception = {}
conan_rootpath_boost_throw_exception = "E:/.conan/9khyzaae/1"

conan_includedirs_boost_type_traits = {"E:/.conan/lqum5pis/1/type_traits/include"}
conan_libdirs_boost_type_traits = {"E:/.conan/lqum5pis/1/type_traits/lib"}
conan_bindirs_boost_type_traits = {"E:/.conan/lqum5pis/1/type_traits/lib"}
conan_libs_boost_type_traits = {}
conan_cppdefines_boost_type_traits = {"BOOST_ALL_NO_LIB=1"}
conan_cppflags_boost_type_traits = {}
conan_cflags_boost_type_traits = {}
conan_sharedlinkflags_boost_type_traits = {}
conan_exelinkflags_boost_type_traits = {}
conan_rootpath_boost_type_traits = "E:/.conan/lqum5pis/1"

conan_includedirs_boost_core = {"E:/.conan/jueckpqg/1/core/include"}
conan_libdirs_boost_core = {"E:/.conan/jueckpqg/1/core/lib"}
conan_bindirs_boost_core = {"E:/.conan/jueckpqg/1/core/lib"}
conan_libs_boost_core = {}
conan_cppdefines_boost_core = {"BOOST_ALL_NO_LIB=1"}
conan_cppflags_boost_core = {}
conan_cflags_boost_core = {}
conan_sharedlinkflags_boost_core = {}
conan_exelinkflags_boost_core = {}
conan_rootpath_boost_core = "E:/.conan/jueckpqg/1"

conan_includedirs_boost_static_assert = {"E:/.conan/tsssljru/1/static_assert/include"}
conan_libdirs_boost_static_assert = {"E:/.conan/tsssljru/1/static_assert/lib"}
conan_bindirs_boost_static_assert = {"E:/.conan/tsssljru/1/static_assert/lib"}
conan_libs_boost_static_assert = {}
conan_cppdefines_boost_static_assert = {"BOOST_ALL_NO_LIB=1"}
conan_cppflags_boost_static_assert = {}
conan_cflags_boost_static_assert = {}
conan_sharedlinkflags_boost_static_assert = {}
conan_exelinkflags_boost_static_assert = {}
conan_rootpath_boost_static_assert = "E:/.conan/tsssljru/1"

conan_includedirs_boost_assert = {"E:/.conan/xf7qytkd/1/assert/include"}
conan_libdirs_boost_assert = {"E:/.conan/xf7qytkd/1/assert/lib"}
conan_bindirs_boost_assert = {"E:/.conan/xf7qytkd/1/assert/lib"}
conan_libs_boost_assert = {}
conan_cppdefines_boost_assert = {"BOOST_ALL_NO_LIB=1"}
conan_cppflags_boost_assert = {}
conan_cflags_boost_assert = {}
conan_sharedlinkflags_boost_assert = {}
conan_exelinkflags_boost_assert = {}
conan_rootpath_boost_assert = "E:/.conan/xf7qytkd/1"

conan_includedirs_boost_config = {"E:/.conan/b7h8j8lo/1/config/include"}
conan_libdirs_boost_config = {"E:/.conan/b7h8j8lo/1/config/lib"}
conan_bindirs_boost_config = {"E:/.conan/b7h8j8lo/1/config/lib"}
conan_libs_boost_config = {}
conan_cppdefines_boost_config = {"BOOST_ALL_NO_LIB=1"}
conan_cppflags_boost_config = {}
conan_cflags_boost_config = {}
conan_sharedlinkflags_boost_config = {}
conan_exelinkflags_boost_config = {}
conan_rootpath_boost_config = "E:/.conan/b7h8j8lo/1"

conan_includedirs_boost_package_tools = {}
conan_libdirs_boost_package_tools = {}
conan_bindirs_boost_package_tools = {}
conan_libs_boost_package_tools = {}
conan_cppdefines_boost_package_tools = {}
conan_cppflags_boost_package_tools = {}
conan_cflags_boost_package_tools = {}
conan_sharedlinkflags_boost_package_tools = {}
conan_exelinkflags_boost_package_tools = {}
conan_rootpath_boost_package_tools = "E:/conan/boost_package_tools/1.66.0/bincrafters/stable/package/5ab84d6acfe1f23c4fae0ab88f26e3a396351ac9"
