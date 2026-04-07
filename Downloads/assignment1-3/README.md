# HomeShare Property Management System

A backend management system built in C++ to handle property rentals, reservations, and inventory categorization. This project demonstrates core object-oriented programming principles, manual memory management, and system integration.

## 🚀 Features
* **Inventory Management:** Add, remove, and categorize rental properties (Apartments, Condos, Bungalows, Townhouses).
* **Reservation Engine:** Process bookings with strict conflict-resolution (prevents double-booking dates).
* **Custom Date Handling:** Implemented a lightweight, custom `Date` class for chronological sorting and validation without relying on external time libraries.
* **Dynamic Reporting:** Generate filtered reports based on property category, specific dates, or rental IDs.

## 💻 Tech Stack
* **Language:** C++11
* **Build Tool:** Make / Makefile
* **Testing:** Custom automated unit and integration testing suite (`Tester.cc`)

## ⚙️ Architecture Highlights
This system was designed with a focus on clean separation of concerns:
* **Encapsulation:** Strict privacy controls on `Rental` and `Reservation` state data.
* **Memory Efficiency:** Utilizes statically allocated arrays (`MAX_ARRAY`) for deterministic memory footprint, avoiding heap fragmentation.
* **Namespaces:** Custom `cat` namespace to safely manage global property categories.

## 🚀 Getting Started

### Prerequisites
* A C++ compiler (e.g., `g++`)
* `make` utility

