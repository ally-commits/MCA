-- phpMyAdmin SQL Dump
-- version 5.1.1
-- https://www.phpmyadmin.net/
--
-- Host: 127.0.0.1
-- Generation Time: Jun 09, 2022 at 08:27 AM
-- Server version: 10.4.22-MariaDB
-- PHP Version: 8.1.2

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Database: `bestjobs`
--

-- --------------------------------------------------------

--
-- Table structure for table `jobdata`
--

CREATE TABLE `jobdata` (
  `id` int(11) NOT NULL,
  `username` varchar(11) NOT NULL,
  `password` varchar(11) NOT NULL,
  `firstName` varchar(11) NOT NULL,
  `lastName` varchar(11) NOT NULL,
  `gender` varchar(11) NOT NULL,
  `nationality` varchar(11) NOT NULL,
  `dob` varchar(11) NOT NULL,
  `email` varchar(11) NOT NULL,
  `phoneNumber` varchar(11) NOT NULL,
  `address` varchar(20) NOT NULL,
  `twitter` varchar(30) NOT NULL,
  `facebook` varchar(30) NOT NULL,
  `google` varchar(30) NOT NULL,
  `ugCgpa` varchar(30) NOT NULL,
  `pgCgpa` varchar(30) NOT NULL,
  `project1` varchar(30) NOT NULL,
  `project2` varchar(30) NOT NULL,
  `project3` varchar(30) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Dumping data for table `jobdata`
--

INSERT INTO `jobdata` (`id`, `username`, `password`, `firstName`, `lastName`, `gender`, `nationality`, `dob`, `email`, `phoneNumber`, `address`, `twitter`, `facebook`, `google`, `ugCgpa`, `pgCgpa`, `project1`, `project2`, `project3`) VALUES
(6, 'Alwin', 'password', 'Alwin', 'Crasat', 'Male', 'Indian', '2022-06-09', 'alwin@manip', '9901969930', 'Teena Villa', 'https://twiiter.com', 'https://fb.com', 'https://google.com', '10', '10', 'Project 1', 'Project2', 'Project3');

--
-- Indexes for dumped tables
--

--
-- Indexes for table `jobdata`
--
ALTER TABLE `jobdata`
  ADD PRIMARY KEY (`id`);

--
-- AUTO_INCREMENT for dumped tables
--

--
-- AUTO_INCREMENT for table `jobdata`
--
ALTER TABLE `jobdata`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=7;
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
