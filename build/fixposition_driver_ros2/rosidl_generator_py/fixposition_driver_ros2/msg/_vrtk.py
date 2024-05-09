# generated from rosidl_generator_py/resource/_idl.py.em
# with input from fixposition_driver_ros2:msg/VRTK.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_VRTK(type):
    """Metaclass of message 'VRTK'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('fixposition_driver_ros2')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'fixposition_driver_ros2.msg.VRTK')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__vrtk
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__vrtk
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__vrtk
            cls._TYPE_SUPPORT = module.type_support_msg__msg__vrtk
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__vrtk

            from geometry_msgs.msg import PoseWithCovariance
            if PoseWithCovariance.__class__._TYPE_SUPPORT is None:
                PoseWithCovariance.__class__.__import_type_support__()

            from geometry_msgs.msg import TwistWithCovariance
            if TwistWithCovariance.__class__._TYPE_SUPPORT is None:
                TwistWithCovariance.__class__.__import_type_support__()

            from geometry_msgs.msg import Vector3
            if Vector3.__class__._TYPE_SUPPORT is None:
                Vector3.__class__.__import_type_support__()

            from std_msgs.msg import Header
            if Header.__class__._TYPE_SUPPORT is None:
                Header.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class VRTK(metaclass=Metaclass_VRTK):
    """Message class 'VRTK'."""

    __slots__ = [
        '_header',
        '_pose_frame',
        '_kin_frame',
        '_pose',
        '_velocity',
        '_acceleration',
        '_fusion_status',
        '_imu_bias_status',
        '_gnss1_status',
        '_gnss2_status',
        '_wheelspeed_status',
        '_version',
    ]

    _fields_and_field_types = {
        'header': 'std_msgs/Header',
        'pose_frame': 'string',
        'kin_frame': 'string',
        'pose': 'geometry_msgs/PoseWithCovariance',
        'velocity': 'geometry_msgs/TwistWithCovariance',
        'acceleration': 'geometry_msgs/Vector3',
        'fusion_status': 'int16',
        'imu_bias_status': 'int16',
        'gnss1_status': 'int16',
        'gnss2_status': 'int16',
        'wheelspeed_status': 'int16',
        'version': 'string',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.NamespacedType(['std_msgs', 'msg'], 'Header'),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['geometry_msgs', 'msg'], 'PoseWithCovariance'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['geometry_msgs', 'msg'], 'TwistWithCovariance'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['geometry_msgs', 'msg'], 'Vector3'),  # noqa: E501
        rosidl_parser.definition.BasicType('int16'),  # noqa: E501
        rosidl_parser.definition.BasicType('int16'),  # noqa: E501
        rosidl_parser.definition.BasicType('int16'),  # noqa: E501
        rosidl_parser.definition.BasicType('int16'),  # noqa: E501
        rosidl_parser.definition.BasicType('int16'),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        from std_msgs.msg import Header
        self.header = kwargs.get('header', Header())
        self.pose_frame = kwargs.get('pose_frame', str())
        self.kin_frame = kwargs.get('kin_frame', str())
        from geometry_msgs.msg import PoseWithCovariance
        self.pose = kwargs.get('pose', PoseWithCovariance())
        from geometry_msgs.msg import TwistWithCovariance
        self.velocity = kwargs.get('velocity', TwistWithCovariance())
        from geometry_msgs.msg import Vector3
        self.acceleration = kwargs.get('acceleration', Vector3())
        self.fusion_status = kwargs.get('fusion_status', int())
        self.imu_bias_status = kwargs.get('imu_bias_status', int())
        self.gnss1_status = kwargs.get('gnss1_status', int())
        self.gnss2_status = kwargs.get('gnss2_status', int())
        self.wheelspeed_status = kwargs.get('wheelspeed_status', int())
        self.version = kwargs.get('version', str())

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.header != other.header:
            return False
        if self.pose_frame != other.pose_frame:
            return False
        if self.kin_frame != other.kin_frame:
            return False
        if self.pose != other.pose:
            return False
        if self.velocity != other.velocity:
            return False
        if self.acceleration != other.acceleration:
            return False
        if self.fusion_status != other.fusion_status:
            return False
        if self.imu_bias_status != other.imu_bias_status:
            return False
        if self.gnss1_status != other.gnss1_status:
            return False
        if self.gnss2_status != other.gnss2_status:
            return False
        if self.wheelspeed_status != other.wheelspeed_status:
            return False
        if self.version != other.version:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def header(self):
        """Message field 'header'."""
        return self._header

    @header.setter
    def header(self, value):
        if __debug__:
            from std_msgs.msg import Header
            assert \
                isinstance(value, Header), \
                "The 'header' field must be a sub message of type 'Header'"
        self._header = value

    @builtins.property
    def pose_frame(self):
        """Message field 'pose_frame'."""
        return self._pose_frame

    @pose_frame.setter
    def pose_frame(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'pose_frame' field must be of type 'str'"
        self._pose_frame = value

    @builtins.property
    def kin_frame(self):
        """Message field 'kin_frame'."""
        return self._kin_frame

    @kin_frame.setter
    def kin_frame(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'kin_frame' field must be of type 'str'"
        self._kin_frame = value

    @builtins.property
    def pose(self):
        """Message field 'pose'."""
        return self._pose

    @pose.setter
    def pose(self, value):
        if __debug__:
            from geometry_msgs.msg import PoseWithCovariance
            assert \
                isinstance(value, PoseWithCovariance), \
                "The 'pose' field must be a sub message of type 'PoseWithCovariance'"
        self._pose = value

    @builtins.property
    def velocity(self):
        """Message field 'velocity'."""
        return self._velocity

    @velocity.setter
    def velocity(self, value):
        if __debug__:
            from geometry_msgs.msg import TwistWithCovariance
            assert \
                isinstance(value, TwistWithCovariance), \
                "The 'velocity' field must be a sub message of type 'TwistWithCovariance'"
        self._velocity = value

    @builtins.property
    def acceleration(self):
        """Message field 'acceleration'."""
        return self._acceleration

    @acceleration.setter
    def acceleration(self, value):
        if __debug__:
            from geometry_msgs.msg import Vector3
            assert \
                isinstance(value, Vector3), \
                "The 'acceleration' field must be a sub message of type 'Vector3'"
        self._acceleration = value

    @builtins.property
    def fusion_status(self):
        """Message field 'fusion_status'."""
        return self._fusion_status

    @fusion_status.setter
    def fusion_status(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'fusion_status' field must be of type 'int'"
            assert value >= -32768 and value < 32768, \
                "The 'fusion_status' field must be an integer in [-32768, 32767]"
        self._fusion_status = value

    @builtins.property
    def imu_bias_status(self):
        """Message field 'imu_bias_status'."""
        return self._imu_bias_status

    @imu_bias_status.setter
    def imu_bias_status(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'imu_bias_status' field must be of type 'int'"
            assert value >= -32768 and value < 32768, \
                "The 'imu_bias_status' field must be an integer in [-32768, 32767]"
        self._imu_bias_status = value

    @builtins.property
    def gnss1_status(self):
        """Message field 'gnss1_status'."""
        return self._gnss1_status

    @gnss1_status.setter
    def gnss1_status(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'gnss1_status' field must be of type 'int'"
            assert value >= -32768 and value < 32768, \
                "The 'gnss1_status' field must be an integer in [-32768, 32767]"
        self._gnss1_status = value

    @builtins.property
    def gnss2_status(self):
        """Message field 'gnss2_status'."""
        return self._gnss2_status

    @gnss2_status.setter
    def gnss2_status(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'gnss2_status' field must be of type 'int'"
            assert value >= -32768 and value < 32768, \
                "The 'gnss2_status' field must be an integer in [-32768, 32767]"
        self._gnss2_status = value

    @builtins.property
    def wheelspeed_status(self):
        """Message field 'wheelspeed_status'."""
        return self._wheelspeed_status

    @wheelspeed_status.setter
    def wheelspeed_status(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'wheelspeed_status' field must be of type 'int'"
            assert value >= -32768 and value < 32768, \
                "The 'wheelspeed_status' field must be an integer in [-32768, 32767]"
        self._wheelspeed_status = value

    @builtins.property
    def version(self):
        """Message field 'version'."""
        return self._version

    @version.setter
    def version(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'version' field must be of type 'str'"
        self._version = value
