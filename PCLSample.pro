TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

QMAKE_CXXFLAGS_WARN_ON += "-Wno-unused-parameter"
QMAKE_CXXFLAGS += -fpermissive

SOURCES += main.cpp \
    objparser.cpp

HEADERS += \
		objparser.h

# PCL
INCLUDEPATH += /usr/local/include/pcl-1.7
LIBS += -L/usr/local/lib \
	-lpcl_2d \
	-lpcl_common \
	-lpcl_features \
	-lpcl_filters \
	-lpcl_io \
	-lpcl_io_ply \
	-lpcl_kdtree \
	-lpcl_keypoints \
	-lpcl_ml \
	-lpcl_octree \
	-lpcl_outofcore \
	-lpcl_recognition \
	-lpcl_registration \
	-lpcl_sample_consensus \
	-lpcl_search \
	-lpcl_segmentation \
	-lpcl_stereo \
	-lpcl_surface \
	-lpcl_tracking \
	-lpcl_visualization

# vtk
INCLUDEPATH += /usr/local/include/vtk-5.10
LIBS += -L/usr/local/lib/vtk-5.10 \
	-lLSDyna \
	-lMapReduceMPI \
	-lmpistubs \
	-lvtkCharts \
	-lvtkCommon \
	-lvtkDICOMParser \
	-lvtkFiltering \
	-lvtkGenericFiltering \
	-lvtkGeovis \
	-lvtkGraphics \
	-lvtkHybrid \
	-lvtkIO \
	-lvtkImaging \
	-lvtkInfovis \
	-lvtkNetCDF \
	-lvtkRendering \
	-lvtkViews \
	-lvtkVolumeRendering \
	-lvtkWidgets \
	-lvtkalglib \
	-lvtkexoIIc \
	-lvtkexpat \
	-lvtkfreetype \
	-lvtkftgl \
	-lvtkjpeg \
	-lvtklibxml2 \
	-lvtkmetaio \
	-lvtkpng \
	-lvtkproj4 \
	-lvtksqlite \
	-lvtksys \
	-lvtktiff \
	-lvtkverdict \
	-lvtkzlib

# libobj
INCLUDEPATH += /usr/local/include
LIBS += -L/usr/local/lib \
	-lobj

# Eigen
INCLUDEPATH += /usr/local/include/eigen3

# boost
macx: LIBS += -L/usr/local/opt/boost/lib/ \
	-lboost_chrono-mt \
	-lboost_date_time-mt \
	-lboost_filesystem-mt \
	-lboost_graph-mt \
	-lboost_iostreams-mt \
	-lboost_locale-mt \
	-lboost_math_c99-mt \
	-lboost_math_c99f-mt \
	-lboost_math_c99l-mt \
	-lboost_math_tr1-mt \
	-lboost_math_tr1f-mt \
	-lboost_math_tr1l-mt \
	-lboost_prg_exec_monitor-mt \
	-lboost_program_options-mt \
	-lboost_python-mt \
	-lboost_random-mt \
	-lboost_regex-mt \
	-lboost_serialization-mt \
	-lboost_signals-mt \
	-lboost_system-mt \
	-lboost_thread-mt \
	-lboost_timer-mt \
	-lboost_unit_test_framework-mt \
	-lboost_wave-mt \
	-lboost_wserialization-mt
INCLUDEPATH += /usr/local/opt/boost/include
