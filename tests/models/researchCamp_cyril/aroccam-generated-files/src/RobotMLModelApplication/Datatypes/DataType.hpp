#ifndef __EFFIBOX_DataType_HPP__
#define __EFFIBOX_DataType_HPP__

//std
#include <string>

//effibox
#include <effibox/clock/date_time.hpp>


typedef bool Bool;
typedef char Byte;
typedef char Char;
typedef int8_t Int8;
typedef uint8_t UInt8;
typedef int16_t Int16;
typedef uint16_t UInt16;
typedef int32_t Int32;
typedef uint32_t UInt32;
typedef int64_t Int64;
typedef uint64_t UInt64;
typedef float Float32;
typedef double Float64;

typedef std::string String;
typedef effibox::date_time Time;
typedef effibox::time_duration Duration;

struct Header
{
	Time stamp;
	String frame_id;
	UInt32 seq;
};

struct MultiArrayDimension
{
	UInt32 stride;
	UInt32 size;
	String label;
};

struct MultiArrayLayout
{
	std::vector<MultiArrayDimension> dim;
	UInt32 data_offset;
};

template <typename T>
struct MultiArray
{
	std::vector<T> data;
	MultiArrayLayout layout;
};

typedef MultiArray<Byte> ByteMultiArray;
typedef MultiArray<Float32> Float32MultiArray;
typedef MultiArray<Float64> Float64MultiArray;
typedef MultiArray<Int8> Int8MultiArray;
typedef MultiArray<Int16> Int16MultiArray;
typedef MultiArray<Int32> Int32MultiArray;
typedef MultiArray<Int64> Int64MultiArray;
typedef MultiArray<UInt8> UInt8MultiArray;
typedef MultiArray<UInt16> UInt16MultiArray;
typedef MultiArray<UInt32> UInt32MultiArray;
typedef MultiArray<UInt64> UInt64MultiArray;

struct ColorRGBA
{
	Float32 r;
	Float32 g;
	Float32 b;
	Float32 a;
};


template<typename T>
struct GerenicPoint
{
  T x;
  T y;
  T z;
};

typedef GerenicPoint<Float64> Point;
typedef GerenicPoint<Float32> Point32;
typedef GerenicPoint<Float64> Vector3;

struct Quaternion
{
	Float64 w;
	Float64 z;
	Float64 y;
	Float64 x;
};

struct Polygon
{
	std::vector<Point32> point; //must have minimum 3 elements 
};

struct Pose
{
	Quaternion orientation;
	Point position;
};

struct Pose2D
{
	Float64 theta;
	Float64 y;
	Float64 x;
};

struct PoseArray
{
	Header header;
	std::vector<Pose> poses;
};

struct Transform
{
	Vector3 translation;
	Quaternion rotation;
};

struct Twist
{
	Vector3 angular;
	Vector3 linear;
};

struct Wrench
{
	Vector3 torque;
	Vector3 force;
};

template<typename T>
struct GenericWithCovariance
{
	T data;
	std::vector<Float64> covariance; //must be 6*6 matrix
};

typedef GenericWithCovariance<Twist> TwistWithCovariance;
typedef GenericWithCovariance<Pose> PoseWithCovariance;

template<typename T>
struct GenericStamped
{
  Header header;
  T data;
};

typedef GenericStamped<Point> PointStamped;
typedef GenericStamped<Polygon> PolygonStamped;
typedef GenericStamped<Vector3> Vector3Stamped;
typedef GenericStamped<Pose> PoseStamped;
typedef GenericStamped<Twist> TwistStamped;
typedef GenericStamped<Quaternion> QuaternionStamped;
typedef GenericStamped<PoseWithCovariance> PoseWithCovarianceStamped;
typedef GenericStamped<Wrench> WrenchStamped;


struct Path
{
	Header header;
	std::vector<PoseStamped> poses;
};

struct Odometry
{
	String child_frame_id;
	Header header;
	TwistWithCovariance twist;
	PoseWithCovariance pose;
};

struct MapMetaData
{
	Time map_load_time;
	Pose origin;
	Float32 resolution;
	UInt32 width;
};

struct OccupancyGrid
{
	Header header;
	MapMetaData info;
	std::vector<Int8> data;
};

struct GridCells
{
	Header header;
	Float32 cell_height;
	Float32 cell_width;
	std::vector<Point> cells;
};


struct RegionOfInterest
{
	UInt32 height;
	Bool do_rectify;
	UInt32 y_offset;
	UInt32 x_offset;
};

struct Range
{
	UInt8 INFRARED;
	Float32 range;
	Header header;
	Float32 min_range;
	Float32 field_of_view;
	Float32 max_range;
	UInt8 radiation_type;
	UInt8 ULTRASOUND;
};

struct CameraInfo
{
	Header header;
	UInt32 height;
	UInt32 width;
	String distorsion_model;
	std::vector<Float64> D;
	std::vector<Float64> K; //must have 9 elements
	std::vector<Float64> R; //must have 9 elements
	std::vector<Float64> P; //must have 12 elements
	UInt32 beginning_x;
	UInt32 beginning_y;
	RegionOfInterest roi;
};

struct Imu
{
	Header header;
	Quaternion orientation;
	std::vector<Float64> orientation_covariance; //must have 9 elements
	Vector3 angular_velocity;
	std::vector<Float64> angular_velocity_covariance; //must have 9 elements
	Vector3 linear_acceleration;
	std::vector<Float64> linear_acceleration_covariance; //must have 9 elements
};

struct LaserScan
{
	Header header;
	Float32 angle_min;
	Float32 angle_max;
	Float32 angle_increment;
	Float32 time_increment;
	Float32 scan_time;
	Float32 range_min;
	Float32 range_max;
	std::vector<Float32> range;
	std::vector<Float32> intensities;
};

struct Image
{
	Header header;
	UInt32 height;
	UInt32 width;
	String encoding;
	UInt8 is_bigendian;
	UInt32 step;
	std::vector<UInt8> data;
};

struct ChannelFloat32
{
	String name;
	std::vector<Float32> values;
};

struct CompressedImage
{
	Header header;
	String format;
	std::vector<UInt8> data;
};

struct PointCloud
{
	Header header;
	std::vector<Point32> points;
	std::vector<ChannelFloat32> channels;
};

struct PointField
{
	UInt32 count;
	UInt8 datatype;
	String name;
	UInt32 offset;
};

struct PointCloud2
{
	Header header;
	UInt32 height;
	UInt32 width;
	std::vector<PointField> fields;
	Bool is_bigendian;
	UInt32 point_step;
	UInt32 row_step;
	std::vector<UInt8> data;
	Bool is_dense;
};

struct JointState
{
	std::vector<Float64> velocity;
	std::vector<Float64> position;
	std::vector<Float64> effort;
	std::vector<String> name;
};

struct NavSatStatus
{
	UInt16 SERVICE_GLONASS;
	UInt16 SERVICE_GALILEO;
	Int8 STATUS_NO_FIX;
	UInt16 SERVICE_COMPASS;
	Int8 STATUS_SBAS_FIX;
	Int8 STATUS_GBAS_FIX;
	Int8 status;
	UInt16 SERVICE_GPS;
	UInt16 service;
	Int8 STATUS_FIX;
};

struct NavSatFix
{
	Int8 STATUS_NO_FIX;
	Int8 STATUS_FIX;
	Int8 STATUS_SBAS_FIX;
	Int8 STATUS_GBAS_FIX;
	Int8 status;

	UInt16 SERVICE_GPS;
	UInt16 SERVICE_GLONASS;
	UInt16 SERVICE_COMPASS;
	UInt16 SERVICE_GALILEO;

	UInt16 service;

	Header header;

	Float64 latitude;
	Float64 longitude;
	Float64 altitude;
	std::vector<Float64> position_covariance;

	UInt8 COVARIANCE_TYPE_UNKNOWN;
	UInt8 COVARIANCE_TYPE_APPROXIMATED;
	UInt8 COVARIANCE_TYPE_DIAGONAL_KNOWN;
	UInt8 COVARIANCE_TYPE_KNOWN;
	UInt8 position_covariance_type;
};

struct Joy
{
	Header header;
	std::vector<Float32> axes;
	std::vector<Int32> buttons;
};

struct JoyFeedback
{
	Float32 intensity;
	UInt8 TYPE_LED;
	UInt8 id;
	UInt8 TYPE_BUZZER;
	UInt8 type;
	UInt8 TYPE_RUMBLE;
};

struct JoyFeedbackArray
{
	std::vector<JoyFeedback> array;
};

struct CarLikeOdometry
{
	Header header;
	Float64 steering_angle;
	Float64 left_rear_wheel_distance;
	Float64 right_rear_wheel_distance;
	Float64 right_rear_wheel_velocity;
	Float64 left_rear_wheel_velocity;
};

struct DifferentialOdometry
{
	Header header;
	Float64 right_distance;
	Float64 left_distance;
	Float64 left_velocity;
	Float64 right_velocity;
};


struct KeyValue
{
	String key;
	String value;
};

struct DiagnosticStatus
{
	Byte OK;
	Byte WARN;
	Byte ERROR;
	Byte level;
	String name;
	String message;
	String hardware_id;
	std::vector<KeyValue> values;
};

struct DiagnosticArray
{
	Header header;
	std::vector<DiagnosticStatus> status;
	std::vector<KeyValue> values;
};


struct GoalID
{
	String id;
	Time stamp;
};

struct GoalStatus
{
	UInt8 PENDING;
	UInt8 ACTIVE;
	UInt8 PREEMPTED;
	UInt8 SUCCEEDED;
	UInt8 ABORTED;
	UInt8 REJECTED;
	UInt8 PREEMPTING;
	UInt8 RECALLING;
	UInt8 RECALLED;
	UInt8 LOST;
	String text;
	UInt8 status;
};

struct GoalStatusArray
{
	Header header;
	std::vector<GoalStatus> status_list;
};

#endif
