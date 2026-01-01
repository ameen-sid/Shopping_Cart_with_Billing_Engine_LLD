# Shopping Cart with Billing Engine

A console-based Shopping Cart application written in C++. This project demonstrates a modular and scalable design for managing products, carts, discounts, taxes, billing, and invoice generation.

## Features

- **Product Management**: Add identifying details for products (Name, Price, ID).
- **Shopping Cart Details**:
    - Add items to cart.
    - Remove items from cart.
    - Update item quantities.
    - View current cart contents and subtotal.
- **Discount Engine**:
    - Support for multiple discount types (Flat amount, Percentage, Threshold-based).
    - Apply multiple discounts sequentially.
- **Tax Calculation**:
    - Configurable tax rates.
    - Tax applied on the discounted amount.
- **Billing & Invoicing**:
    - Generates itemized invoices.
    - Displays detailed breakdown: Subtotal, Total Discount, Tax Amount, and Final Payable Amount.
    - **Persistence**: Saves the generated invoice to `invoice.txt`.

## Project Structure

The project follows a clean architecture with separate modules for different responsibilities:

- `src/`
    - `main.cpp`: Entry point of the application.
    - `product/`: Product entity definition.
    - `cart/`: Cart management logic.
    - `discount/`: Discount policies (Flat, Percentage, etc.).
    - `tax/`: Tax calculation logic.
    - `billing/`: Orchestrates the billing process.
    - `invoice/`: Handles invoice formatting and display.
    - `storage/`: Manages file I/O for invoices.
    - `ui/`: User interaction layer (Menu-driven interface).

## Getting Started

### Prerequisites

- A C++ Compiler (supporting C++11 or later), such as GCC (g++) or Clang.

### compilation

To compile the project, run the following command from the project root directory:

```bash
g++ -std=c++17 -o ShoppingCart src/main.cpp src/product/*.cpp src/cart/*.cpp src/discount/*.cpp src/tax/*.cpp src/billing/*.cpp src/invoice/*.cpp src/storage/*.cpp src/ui/*.cpp
```

### Running the Application

After successful compilation, execute the generated binary:

**Windows:**
```powershell
.\ShoppingCart.exe
```

**Linux/macOS:**
```bash
./ShoppingCart
```

## Low Level Design (LLD)

The project is designed with SOLID principles in mind, ensuring loose coupling and high cohesion.

- **Responsibilities**:
    - **Cart**: Managing items and calculating subtotal.
    - **Billing**: Stateless component that coordinates discounts and taxes to compute the final bill.
    - **Storage**: Abstracted interface for saving bills (currently implements FileStorage).

- **Constraints**:
    - Product details are immutable.
    - Discounts are applied before tax.
    - Tax is calculated on the discounted value.
    - Invoice files are overwritten on each new bill generation.
