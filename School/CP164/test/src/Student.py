"""
-------------------------------------------------------
Student class definition.
Stores simple student data.
-------------------------------------------------------
Author:  David Brown
ID:      999999999
Email:   dbrown@wlu.ca
__updated__ = "2019-09-05"
-------------------------------------------------------
"""


class Student:
    """
    -------------------------------------------------------
    Constants
    -------------------------------------------------------
    """
    GENDERS = ("F", "M", "T")  # Define allowed gender values.

    def __init__(self, student_id, surname, forename, gender, birth_date):
        """
        -------------------------------------------------------
        Initializes the student attributes.
        Use: student = Student(student_id, surname, forename, gender, birth_date)
        -------------------------------------------------------
        Parameters:
            student_id - 9 digit student ID (str)
            surname - student family (str)
            forename - student given name (str)
            gender - student gender [a character in GENDERS] (str)
            birth_date - a student birth date of the form YYYY-MM-DD (str)
        Returns:
            A Student object.
        -------------------------------------------------------
        """
        assert gender in Student.GENDERS, \
            "Gender must be one of {}".format(Student.GENDERS)
        assert len(student_id) == 9 and student_id.isdigit(), \
            "Student ID must be a 9 digit string"

        self.student_id = student_id
        self.surname = surname
        self.forename = forename
        self.gender = gender
        self.birth_date = birth_date

    def __str__(self):
        """
        -------------------------------------------------------
        Returns a string version of a student in the format
        id
        surname, forename
        gender, birthdate
        Use: print(student)
        Use: print( "{}".format(student))
        Use: string = str(student)
        -------------------------------------------------------
        Returns:
            string - a formatted version of the student data (str)
        -------------------------------------------------------
        """
        string = """{}
{}, {}
{}, {}""".format(self.student_id, self.surname,
                 self.forename, self.gender, self.birth_date,)
        return string

    def __eq__(self, other):
        """
        -------------------------------------------------------
        Compares against another student for equality.
        Use: student == other
        -------------------------------------------------------
        Parameters:
            other - other student to compare to (Student)
        Returns:
            result - True if student IDs match, False otherwise (boolean)
        -------------------------------------------------------
        """
        result = self.student_id == other.student_id
        return result

    def __lt__(self, other):
        """
        -------------------------------------------------------
        Determines if this student precedes another.
        If student IDs don't match (using already defined == operator),
        compares students by name then by ID.
        Use: student < other
        -------------------------------------------------------
        Parameters:
            other - other student to compare to (Student)
        Returns:
            result - True if student less than other, False otherwise (boolean)
        -------------------------------------------------------
        """
        if self == other:
            result = False
        else:
            # Compare the data values by putting them into tuples.
            result = \
                (self.surname.lower(), self.forename.lower(), self.birth_date) < \
                (other.surname.lower(), other.forename.lower(), other.birth_date)
        return result

    def __le__(self, other):
        """
        -------------------------------------------------------
        Determines if this student precedes is or equal to another.
        Uses already defined == and < operators.
        Use: student <= other
        -------------------------------------------------------
        Parameters:
            other - other student to compare to (Student)
        Returns:
            result - True if student less than or equal to other,
                False otherwise (boolean)
        -------------------------------------------------------
        """
        result = (self == other or self < other)
        return result

    def login(self):
        """
        -------------------------------------------------------
        Generates and returns a Laurier-compatible Network login.
        Use: login = student.login()
        -------------------------------------------------------
        Returns:
            result - a Network login consisting of the first four
                characters of surname and the last four digits of student)id.
                Total with is 8, special characters (" ", "'", "-") are replaced
                with 'x'. (str)
        -------------------------------------------------------
        """
        # Convert to lower case and get first four characters.
        result = self.surname.lower()[:4]
        # Replace trailing spaces with 'x'.
        result = "{:x<4}".format(result)
        # Replace special characters with 'x'.
        result = result.replace(' ', 'x')
        result = result.replace("'", 'x')
        result = result.replace("-", 'x')
        # Add the last four digits of the ID number.
        result += self.student_id[-4:]
        return result

    def email(self):
        """
        -------------------------------------------------------
        Generates and returns a Laurier-compatible email address.
        Use: email = student.email()
        -------------------------------------------------------
        Returns:
            result - a Laurier email address of the form
                login@mylaurier.ca (str)
        -------------------------------------------------------
        """
        result = self.login() + "@mylaurier.ca"
        return result

    def write(self, fv):
        """
        -------------------------------------------------------
        Writes this student's attributes to an already open
        comma-delimited file.
        Use: student.write(fv)
        -------------------------------------------------------
        Parameters:
            fv - a file variable, open for writing or appending (file)
        Returns:
            None
        -------------------------------------------------------
        """
        string = "{},{},{},{},{}".format(self.student_id, self.surname,
                                         self.forename, self.gender, self.birth_date)
        print(string, file=fv)
        return