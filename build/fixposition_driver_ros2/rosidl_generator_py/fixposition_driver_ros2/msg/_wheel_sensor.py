# generated from rosidl_generator_py/resource/_idl.py.em
# with input from fixposition_driver_ros2:msg/WheelSensor.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_WheelSensor(type):
    """Metaclass of message 'WheelSensor'."""

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
                'fixposition_driver_ros2.msg.WheelSensor')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__wheel_sensor
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__wheel_sensor
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__wheel_sensor
            cls._TYPE_SUPPORT = module.type_support_msg__msg__wheel_sensor
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__wheel_sensor

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


class WheelSensor(metaclass=Metaclass_WheelSensor):
    """Message class 'WheelSensor'."""

    __slots__ = [
        '_header',
        '_location',
        '_vx',
        '_vy',
        '_vz',
        '_vx_valid',
        '_vy_valid',
        '_vz_valid',
    ]

    _fields_and_field_types = {
        'header': 'std_msgs/Header',
        'location': 'string',
        'vx': 'int32',
        'vy': 'int32',
        'vz': 'int32',
        'vx_valid': 'boolean',
        'vy_valid': 'boolean',
        'vz_valid': 'boolean',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.NamespacedType(['std_msgs', 'msg'], 'Header'),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        from std_msgs.msg import Header
        self.header = kwargs.get('header', Header())
        self.location = kwargs.get('location', str())
        self.vx = kwargs.get('vx', int())
        self.vy = kwargs.get('vy', int())
        self.vz = kwargs.get('vz', int())
        self.vx_valid = kwargs.get('vx_valid', bool())
        self.vy_valid = kwargs.get('vy_valid', bool())
        self.vz_valid = kwargs.get('vz_valid', bool())

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
        if self.location != other.location:
            return False
        if self.vx != other.vx:
            return False
        if self.vy != other.vy:
            return False
        if self.vz != other.vz:
            return False
        if self.vx_valid != other.vx_valid:
            return False
        if self.vy_valid != other.vy_valid:
            return False
        if self.vz_valid != other.vz_valid:
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
    def location(self):
        """Message field 'location'."""
        return self._location

    @location.setter
    def location(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'location' field must be of type 'str'"
        self._location = value

    @builtins.property
    def vx(self):
        """Message field 'vx'."""
        return self._vx

    @vx.setter
    def vx(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'vx' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'vx' field must be an integer in [-2147483648, 2147483647]"
        self._vx = value

    @builtins.property
    def vy(self):
        """Message field 'vy'."""
        return self._vy

    @vy.setter
    def vy(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'vy' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'vy' field must be an integer in [-2147483648, 2147483647]"
        self._vy = value

    @builtins.property
    def vz(self):
        """Message field 'vz'."""
        return self._vz

    @vz.setter
    def vz(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'vz' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'vz' field must be an integer in [-2147483648, 2147483647]"
        self._vz = value

    @builtins.property
    def vx_valid(self):
        """Message field 'vx_valid'."""
        return self._vx_valid

    @vx_valid.setter
    def vx_valid(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'vx_valid' field must be of type 'bool'"
        self._vx_valid = value

    @builtins.property
    def vy_valid(self):
        """Message field 'vy_valid'."""
        return self._vy_valid

    @vy_valid.setter
    def vy_valid(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'vy_valid' field must be of type 'bool'"
        self._vy_valid = value

    @builtins.property
    def vz_valid(self):
        """Message field 'vz_valid'."""
        return self._vz_valid

    @vz_valid.setter
    def vz_valid(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'vz_valid' field must be of type 'bool'"
        self._vz_valid = value
