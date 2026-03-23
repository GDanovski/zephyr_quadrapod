/*
 * Copyright (C) 2026 Georgi Danovski
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

#ifndef ZEPHYR_QUADRAPOD_LEG_H_
#define ZEPHYR_QUADRAPOD_LEG_H_

#include <zephyr/kernel.h>
#include <zephyr/device.h>

/**
 * @brief Represents a single leg with two servos
 *
 * A leg contains:
 * - servo0: coxa servo (hip)
 * - servo1: femur servo (knee)
 */
struct leg
{
    const struct device *coxa;  /* Hip servo */
    const struct device *femur; /* Knee servo */
};

/**
 * @brief Initialize a leg module with its servos
 *
 * @param leg_dev Pointer to leg device structure
 * @return 0 on success, negative errno on failure
 */
int leg_init(struct leg *leg_dev);

/**
 * @brief Set coxa (hip) servo position
 *
 * @param leg_dev Pointer to leg device structure
 * @param pulse_us Pulse width in microseconds
 * @return 0 on success, negative errno on failure
 */
int leg_set_coxa(struct leg *leg_dev, uint32_t pulse_us);

/**
 * @brief Set femur (knee) servo position
 *
 * @param leg_dev Pointer to leg device structure
 * @param pulse_us Pulse width in microseconds
 * @return 0 on success, negative errno on failure
 */
int leg_set_femur(struct leg *leg_dev, uint32_t pulse_us);

#endif /* ZEPHYR_QUADRAPOD_LEG_H_ */
