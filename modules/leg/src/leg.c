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

#include <leg.h>
#include <zephyr/logging/log.h>

LOG_MODULE_REGISTER(leg, CONFIG_LOG_DEFAULT_LEVEL);

int leg_init(struct leg *leg_dev)
{
    if (!leg_dev)
    {
        LOG_ERR("Invalid leg device pointer");
        return -EINVAL;
    }

    /* Get servo devices from device tree */
    leg_dev->coxa = device_get_binding("servo0");
    leg_dev->femur = device_get_binding("servo1");

    if (!leg_dev->coxa)
    {
        LOG_ERR("Coxa servo (servo0) not found in device tree");
        return -ENODEV;
    }

    if (!leg_dev->femur)
    {
        LOG_ERR("Femur servo (servo1) not found in device tree");
        return -ENODEV;
    }

    LOG_INF("Leg module initialized successfully");
    return 0;
}

int leg_set_coxa(struct leg *leg_dev, uint32_t pulse_us)
{
    if (!leg_dev || !leg_dev->coxa)
    {
        LOG_ERR("Invalid leg device or coxa servo");
        return -EINVAL;
    }

    /* TODO: Implement PWM control for coxa servo */
    LOG_DBG("Setting coxa servo to %u us", pulse_us);
    return 0;
}

int leg_set_femur(struct leg *leg_dev, uint32_t pulse_us)
{
    if (!leg_dev || !leg_dev->femur)
    {
        LOG_ERR("Invalid leg device or femur servo");
        return -EINVAL;
    }

    /* TODO: Implement PWM control for femur servo */
    LOG_DBG("Setting femur servo to %u us", pulse_us);
    return 0;
}
