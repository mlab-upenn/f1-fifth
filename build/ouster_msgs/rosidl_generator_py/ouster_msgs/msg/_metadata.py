# generated from rosidl_generator_py/resource/_idl.py.em
# with input from ouster_msgs:msg/Metadata.idl
# generated code does not contain a copyright notice


# Import statements for member types

# Member 'beam_azimuth_angles'
# Member 'beam_altitude_angles'
# Member 'imu_to_sensor_transform'
# Member 'lidar_to_sensor_transform'
import array  # noqa: E402, I100

import builtins  # noqa: E402, I100

import math  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_Metadata(type):
    """Metaclass of message 'Metadata'."""

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
            module = import_type_support('ouster_msgs')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'ouster_msgs.msg.Metadata')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__metadata
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__metadata
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__metadata
            cls._TYPE_SUPPORT = module.type_support_msg__msg__metadata
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__metadata

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class Metadata(metaclass=Metaclass_Metadata):
    """Message class 'Metadata'."""

    __slots__ = [
        '_hostname',
        '_lidar_mode',
        '_timestamp_mode',
        '_beam_azimuth_angles',
        '_beam_altitude_angles',
        '_imu_to_sensor_transform',
        '_lidar_to_sensor_transform',
        '_serial_no',
        '_firmware_rev',
        '_imu_port',
        '_lidar_port',
    ]

    _fields_and_field_types = {
        'hostname': 'string',
        'lidar_mode': 'string',
        'timestamp_mode': 'string',
        'beam_azimuth_angles': 'sequence<double>',
        'beam_altitude_angles': 'sequence<double>',
        'imu_to_sensor_transform': 'sequence<double>',
        'lidar_to_sensor_transform': 'sequence<double>',
        'serial_no': 'string',
        'firmware_rev': 'string',
        'imu_port': 'int8',
        'lidar_port': 'int8',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.BasicType('double')),  # noqa: E501
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.BasicType('double')),  # noqa: E501
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.BasicType('double')),  # noqa: E501
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.BasicType('double')),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.BasicType('int8'),  # noqa: E501
        rosidl_parser.definition.BasicType('int8'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.hostname = kwargs.get('hostname', str())
        self.lidar_mode = kwargs.get('lidar_mode', str())
        self.timestamp_mode = kwargs.get('timestamp_mode', str())
        self.beam_azimuth_angles = array.array('d', kwargs.get('beam_azimuth_angles', []))
        self.beam_altitude_angles = array.array('d', kwargs.get('beam_altitude_angles', []))
        self.imu_to_sensor_transform = array.array('d', kwargs.get('imu_to_sensor_transform', []))
        self.lidar_to_sensor_transform = array.array('d', kwargs.get('lidar_to_sensor_transform', []))
        self.serial_no = kwargs.get('serial_no', str())
        self.firmware_rev = kwargs.get('firmware_rev', str())
        self.imu_port = kwargs.get('imu_port', int())
        self.lidar_port = kwargs.get('lidar_port', int())

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
        if self.hostname != other.hostname:
            return False
        if self.lidar_mode != other.lidar_mode:
            return False
        if self.timestamp_mode != other.timestamp_mode:
            return False
        if self.beam_azimuth_angles != other.beam_azimuth_angles:
            return False
        if self.beam_altitude_angles != other.beam_altitude_angles:
            return False
        if self.imu_to_sensor_transform != other.imu_to_sensor_transform:
            return False
        if self.lidar_to_sensor_transform != other.lidar_to_sensor_transform:
            return False
        if self.serial_no != other.serial_no:
            return False
        if self.firmware_rev != other.firmware_rev:
            return False
        if self.imu_port != other.imu_port:
            return False
        if self.lidar_port != other.lidar_port:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def hostname(self):
        """Message field 'hostname'."""
        return self._hostname

    @hostname.setter
    def hostname(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'hostname' field must be of type 'str'"
        self._hostname = value

    @builtins.property
    def lidar_mode(self):
        """Message field 'lidar_mode'."""
        return self._lidar_mode

    @lidar_mode.setter
    def lidar_mode(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'lidar_mode' field must be of type 'str'"
        self._lidar_mode = value

    @builtins.property
    def timestamp_mode(self):
        """Message field 'timestamp_mode'."""
        return self._timestamp_mode

    @timestamp_mode.setter
    def timestamp_mode(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'timestamp_mode' field must be of type 'str'"
        self._timestamp_mode = value

    @builtins.property
    def beam_azimuth_angles(self):
        """Message field 'beam_azimuth_angles'."""
        return self._beam_azimuth_angles

    @beam_azimuth_angles.setter
    def beam_azimuth_angles(self, value):
        if isinstance(value, array.array):
            assert value.typecode == 'd', \
                "The 'beam_azimuth_angles' array.array() must have the type code of 'd'"
            self._beam_azimuth_angles = value
            return
        if __debug__:
            from collections.abc import Sequence
            from collections.abc import Set
            from collections import UserList
            from collections import UserString
            assert \
                ((isinstance(value, Sequence) or
                  isinstance(value, Set) or
                  isinstance(value, UserList)) and
                 not isinstance(value, str) and
                 not isinstance(value, UserString) and
                 all(isinstance(v, float) for v in value) and
                 all(not (val < -1.7976931348623157e+308 or val > 1.7976931348623157e+308) or math.isinf(val) for val in value)), \
                "The 'beam_azimuth_angles' field must be a set or sequence and each value of type 'float' and each double in [-179769313486231570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368.000000, 179769313486231570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368.000000]"
        self._beam_azimuth_angles = array.array('d', value)

    @builtins.property
    def beam_altitude_angles(self):
        """Message field 'beam_altitude_angles'."""
        return self._beam_altitude_angles

    @beam_altitude_angles.setter
    def beam_altitude_angles(self, value):
        if isinstance(value, array.array):
            assert value.typecode == 'd', \
                "The 'beam_altitude_angles' array.array() must have the type code of 'd'"
            self._beam_altitude_angles = value
            return
        if __debug__:
            from collections.abc import Sequence
            from collections.abc import Set
            from collections import UserList
            from collections import UserString
            assert \
                ((isinstance(value, Sequence) or
                  isinstance(value, Set) or
                  isinstance(value, UserList)) and
                 not isinstance(value, str) and
                 not isinstance(value, UserString) and
                 all(isinstance(v, float) for v in value) and
                 all(not (val < -1.7976931348623157e+308 or val > 1.7976931348623157e+308) or math.isinf(val) for val in value)), \
                "The 'beam_altitude_angles' field must be a set or sequence and each value of type 'float' and each double in [-179769313486231570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368.000000, 179769313486231570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368.000000]"
        self._beam_altitude_angles = array.array('d', value)

    @builtins.property
    def imu_to_sensor_transform(self):
        """Message field 'imu_to_sensor_transform'."""
        return self._imu_to_sensor_transform

    @imu_to_sensor_transform.setter
    def imu_to_sensor_transform(self, value):
        if isinstance(value, array.array):
            assert value.typecode == 'd', \
                "The 'imu_to_sensor_transform' array.array() must have the type code of 'd'"
            self._imu_to_sensor_transform = value
            return
        if __debug__:
            from collections.abc import Sequence
            from collections.abc import Set
            from collections import UserList
            from collections import UserString
            assert \
                ((isinstance(value, Sequence) or
                  isinstance(value, Set) or
                  isinstance(value, UserList)) and
                 not isinstance(value, str) and
                 not isinstance(value, UserString) and
                 all(isinstance(v, float) for v in value) and
                 all(not (val < -1.7976931348623157e+308 or val > 1.7976931348623157e+308) or math.isinf(val) for val in value)), \
                "The 'imu_to_sensor_transform' field must be a set or sequence and each value of type 'float' and each double in [-179769313486231570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368.000000, 179769313486231570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368.000000]"
        self._imu_to_sensor_transform = array.array('d', value)

    @builtins.property
    def lidar_to_sensor_transform(self):
        """Message field 'lidar_to_sensor_transform'."""
        return self._lidar_to_sensor_transform

    @lidar_to_sensor_transform.setter
    def lidar_to_sensor_transform(self, value):
        if isinstance(value, array.array):
            assert value.typecode == 'd', \
                "The 'lidar_to_sensor_transform' array.array() must have the type code of 'd'"
            self._lidar_to_sensor_transform = value
            return
        if __debug__:
            from collections.abc import Sequence
            from collections.abc import Set
            from collections import UserList
            from collections import UserString
            assert \
                ((isinstance(value, Sequence) or
                  isinstance(value, Set) or
                  isinstance(value, UserList)) and
                 not isinstance(value, str) and
                 not isinstance(value, UserString) and
                 all(isinstance(v, float) for v in value) and
                 all(not (val < -1.7976931348623157e+308 or val > 1.7976931348623157e+308) or math.isinf(val) for val in value)), \
                "The 'lidar_to_sensor_transform' field must be a set or sequence and each value of type 'float' and each double in [-179769313486231570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368.000000, 179769313486231570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368.000000]"
        self._lidar_to_sensor_transform = array.array('d', value)

    @builtins.property
    def serial_no(self):
        """Message field 'serial_no'."""
        return self._serial_no

    @serial_no.setter
    def serial_no(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'serial_no' field must be of type 'str'"
        self._serial_no = value

    @builtins.property
    def firmware_rev(self):
        """Message field 'firmware_rev'."""
        return self._firmware_rev

    @firmware_rev.setter
    def firmware_rev(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'firmware_rev' field must be of type 'str'"
        self._firmware_rev = value

    @builtins.property
    def imu_port(self):
        """Message field 'imu_port'."""
        return self._imu_port

    @imu_port.setter
    def imu_port(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'imu_port' field must be of type 'int'"
            assert value >= -128 and value < 128, \
                "The 'imu_port' field must be an integer in [-128, 127]"
        self._imu_port = value

    @builtins.property
    def lidar_port(self):
        """Message field 'lidar_port'."""
        return self._lidar_port

    @lidar_port.setter
    def lidar_port(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'lidar_port' field must be of type 'int'"
            assert value >= -128 and value < 128, \
                "The 'lidar_port' field must be an integer in [-128, 127]"
        self._lidar_port = value
