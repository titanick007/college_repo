show databases;
create database Lab_dbms_schema;
use Lab_dbms_schema;
create table student;
drop table student;
show databases;
use  Lab_dbms_schema;
show tables;
create table student(
	Student_ID char(4),
    Student_name varchar(25),
    GPA float,
    Major varchar(20));
show tables;
alter table student
modify column GPA float;
insert into student values
	('S001','Akash Kumar',9.4,'Computer Science'),
    ('S002','Sujit Sharma',8.4,'Computer Science'),
    ('S003','Suman Roy',5.5, 'Chemistry'),
    ('S004','Priya Raj',6.7,'Biology'),
    ('S005','Sumit Kumar',7.7,'Biology'),
    ('S006','Neeraj Patel',8.9,'Chemistry'),
    ('S007','Manali Das',8.2,'Biology'),
    ('S008','Kamal Yadav',7.9,'Computer Science');
select * from student;
select Student_name,GPA from student where GPA>7;